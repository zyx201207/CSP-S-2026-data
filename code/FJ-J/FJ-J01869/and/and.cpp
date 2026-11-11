#include<bits/stdc++.h> 
using namespace std;
long long a[200005],b[35],d[35],e,n,m,s,s1[200005],s2[200005],s3,s4;
int c[35][200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		e=a[i];
		s=0;
		while(e>0){
			b[s]+=e%2;
			if(e%2){
				c[s][b[s]]=i;
			}
			s++;
			e/=2;
		}
	}
	s=0;
	for(int i=31;i>=0;i--){
		if(b[i]>=m){
			s4=0;
			for(int j=1;j<=b[i];j++){
				if(s2[c[i][j]]==s3)s4++;
				s2[c[i][j]]++;
			}			
			if(s4>=m){
				s+=pow(2,i);
				s3++;
			}
			else{
				for(int j=1;j<=b[i];j++){
					s2[c[i][j]]--;
				}
			}			
		}
	}
	cout<<s;
	return 0;
}
