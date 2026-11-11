#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
string s,bp;
ll n,num;
int a[N];
char b[N];
int t[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.ans","w",stdout);
	cin>>n;
	for(ll i=0;i<n;i++){
		cin>>a[i]>>b[i];
		for(ll j=0;j<a[i];j++){
			s[num]=b[i];
			bp[num]=s[num];
			num++;
			t[b[i]-'a']++;
		}
	}
	//要先给出回文的标准字符串
	int ansss=0;
	for(ll i=0;i<num/2;i++){
		char x=bp[i],y=bp[num-i-1];
		if(x!=y){
			if(t[x-'a']%2==0){//可以凑对子
				int x1;//标记可以交换的
				int y1;//比较现在的和以前的 
				for(ll j=num/2;j<num;j++){
					int kk=0;
					if(((bp[j]==x)&&(bp[j-num/2]!=bp[j]))||(bp[j-num/2]==x)&&(bp[j-num/2]!=bp[j])){
						kk=1;
					}
					if((bp[j-num/2]==y)||(bp[j]==y)){
						kk++;
					}
					if(max(kk,y1)==kk){
						x1=j-num/2;
					}
				}
				char xx=bp[x1];
				bp[x1]=x;
				bp[i]=xx;
				ansss++;
			}else if(t[y-'a']%2==0){//可以凑对子
				int x1;//标记可以交换的
				int y1;//比较现在的和以前的 
				for(ll j=num/2;j<num;j++){
					int kk=0;
					if(((bp[j]==y)&&(bp[j-num/2]!=bp[j]))||(bp[j-num/2]==y)&&(bp[j-num/2]!=bp[j])){
						kk=1;
					}
					if((bp[j-num/2]==x)||(bp[j]==x)){
						kk++;
					}
					if(max(kk,y1)==kk){
						x1=j-num/2;
					}
				}
				char xx=bp[x1];
				bp[x1]=y;
				bp[i]=xx;
				ansss++;
			}
		}
	}
	cout<<ansss;
	return 0;
} 
