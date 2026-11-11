#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long n,m,a[N],jun=0,cnt=1;
long long abs(int x,int y){
	if(x>y)return x-y;
	else return y-x;
}
bool a1[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	jun=a[(n+1)/2];
	long long dont=(n+1)/2;
	for(int i=1;i<=n;i++){
		if(a[i]==jun&&i!=dont){
			cnt++;
			a1[i]=true;
		}
	}
	long long neer,num;
	while(m>0){
	neer=INT_MAX,num=0;
	for(int i=1;i<=n;i++){
		if((abs(a[i],jun)<=neer)&&(i!=dont)&&(a1[i]!=true)){
			neer=abs(a[i],jun);
			num=i;
		}
	}
	if(m>=1){
		if(abs(a[num],jun)==1&&num!=0){
			m--;
			cnt++;
			a[num]=jun;
			a1[num]=true;
		}
		else if(a[num]<jun){
			a[num]+=1;
			m--;
		}
		else{
			a[num]-=1;
			m--;
		}
	}
}
	cout<<cnt;
	return 0;
}
