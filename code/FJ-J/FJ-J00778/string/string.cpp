#include<bits/stdc++.h>
using namespace std;
int n,g1[500001],g2[500001];
long long l,s,q1=1,q2=1;
char c1[500001],c2[500001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>g1[i]>>c1[i];
		g2[n-i+1]=g1[i];
		c2[n-i+1]=c1[i];
		l+=g1[i];
	}
	for(long long i=1;i<=l/2;){
		if(g1[q1]==g2[q2]){
			if(c1[q1]!=c2[q2]){
				s+=g1[q1];
			}
			i+=g1[q1];
			q1++;
			q2++;
		}
		else if(g1[q1]>g2[q2]){
			if(c1[q1]!=c2[q2]){
				s+=g2[q2];
			}
			i+=g2[q2];
			g1[q1]-=g2[q2];
			q2++; 
		}
		else{
			if(c1[q1]!=c2[q2]){
				s+=g1[q1];
			}
			i+=g1[q1];
			g2[q2]-=g1[q1];
			q1++; 
		}
	}
	cout<<s;
	return 0;
}
