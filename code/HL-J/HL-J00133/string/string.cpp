#include<bits/stdc++.h>
using namespace std;
int n;
long long num[1000000000000];
char c[1000000000000];
long long w1=0;
void pan(long long q,long long p,int q1,int q2)
{
	if(q1>q2) return;
	if(p=q){
		if(c[q1]!=c[q2]){
			w1=w1+p;
		}
		pan(num[q1+1],num[q2-1],q1+1,q2-1);
	}
	if(q>p){
		if(c[q1]!=c[q2]){
			w1=w1+p;
		}
		pan(q-p,num[q2-1],q1,q2-1);
	}
	if(p>q){
		if(c[q1]!=c[q2]){
			w1=w1+q;
		}
		pan(num[q1+1],p-q,q1+1,q2);
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num[i]>>c[i];
	}
	pan(num[1],num[n],1,n);
	cout<<w1;
}
