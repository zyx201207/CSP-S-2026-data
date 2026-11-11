#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n;
	
	cin>>n;
	
	long long m=0,b=0;
	
	int a[n+1]={};
	
	string c[n+1]={};
	
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		m+=a[i];
		}
		
	string S[m+1]={0};
	
	string s1[m+1]={0};
	
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i]+a[i-1];j++){
			S[j]=c[i];			
			}
		}
		
		for(int i=m;i>1;i--){
			s1[m+1-i]=S[i];
			}
		for(int i=1;i<m;i++){
			if(s1[i]!=S[i]){
				b++;
				}
			
			}
	cout<<b;
	fclose(stdin);
	fclose(stdout);
	return 0;

}
