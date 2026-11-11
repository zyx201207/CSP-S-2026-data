#include<bits/stdc++.h>
#define ll long long
const int N = 2e5+10;
using namespace std;
template <typename T>
inline bool read(T &sum){
	int c = sum = 0;
	while(c<'0'||c>'9')if(c==EOF)return 0;else c=getchar();
	while(c>='0'&&c<='9')sum=(sum<<1)+(sum<<3)+c-'0',c=getchar();
	return 1;
}
struct area{
	ll l,r;
	char c;
};
bool operator < (area a, area b){
	if(a.l == b.l) return a.r >= b.r;
	return a.l >= b.l;
}
priority_queue<area > q;
inline readc(char &c){
	c = ' ';
	while(c==' '||c=='\n')c=getchar();
}
ll n, mid,ded;
ll len[N],a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	read(n);len[0] = 0;
	for(int i = 1; i <= n; i++)
		read(a[i]),readc(c[i]),
		len[i]=a[i]+len[i-1];
	//cout << len[n] << endl;
	mid = (len[n]+1)/2;ded=mid;
	for(int i = 1; i <= n; i++){
		if(len[i-1] <= mid && len[i] >= mid){
			if(len[n]%2){
				q.push((area){len[i-1],mid,c[i]}),
				q.push((area){2*mid-len[i]-1,mid,c[i]});
			}else{
				if(len[i] == mid){
					q.push((area){len[i-1],len[i],c[i]});
				}else if(len[i-1] == mid){
					q.push((area){mid-1,mid,c[i]});
					q.push((area){2*mid-len[i],mid,c[i]});
				}else{
					q.push((area){len[i-1],mid,c[i]});
					q.push((area){2*mid-len[i],mid,c[i]});
				}
			}
		}
		else if(len[i] < mid)
			q.push((area){len[i-1],len[i],c[i]});
		else
			q.push((area){len[n]-len[i],len[n]-len[i-1],c[i]});
	}//*
	while(!q.empty()){
		area i = q.top(); q.pop();
		if(q.empty()) break;
		area j = q.top(); q.pop();
		if(i.l <= j.l && i.r > j.r) q.push(i);
		if(j.l <= i.l && j.r > i.r) q.push(j);
		//cout << i.l << i.c << i.r << " - " << j.l << j.c << j.r << endl;
		if(i.c == j.c) ded-=min(i.r-i.l,j.r-j.l);
	}
	cout << ded;/*/
	while(!q.empty()){
		area i = q.top(); q.pop();
		cout << i.l << " " << i.c << " " << i.r << endl;
	}//*/
	return 0;
}
