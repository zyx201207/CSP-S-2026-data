#include<bits/stdc++.h>
using namespace std;
long long a[510200],s[530003];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		s[i]=a[i]+s[i-1];
	}sort(a+1,a+1+n);
	if(m==0){
		long long cure=0,rule=0;
		for(int i=2; i<=n; i++){
			if(a[i]==a[i-1]){
				cure++;
			}else{
				rule=max(rule,cure);
				cure=0;
			}
		}
		cout<<rule;
	}else{
		int ans=0;
		for(int i=1; i<n; i++){
			for(int j=1; j<i; j++){
				if(a[i]!=a[i+1]){
				if(m>=((i-1)*a[i])-(s[i]-s[j-1])){
				    	ans=max(ans,(i-j+1));
				    }else{
			    		break;
	            	}
			    }
			}
    	}cout<<ans;
    }
	fclose(stdin);
	fclose(stdout);
	return 0;
}
