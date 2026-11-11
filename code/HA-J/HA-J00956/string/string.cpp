#include<bits/stdc++.h>
using namespace std;
string s;
long long a[200100];
string c;
long long n,l,al,ans; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		l+=a[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
			
		}
		
	}
	al=l/2;
    for(long long i=0;i<al;i++){
    	if(s[i]!=s[l-1-i])ans++;
    
    }
	
	cout<<ans;
	
	
	
	return 0;
}





