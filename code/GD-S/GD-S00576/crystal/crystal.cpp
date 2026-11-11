#include<bits/stdc++.h> 
using namespace std;
int n;
long long m,a[5000005],ans,tmp,c[5000005],v;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n>5000){
		int b=a[2]-a[1],s=0;
		for(int i=1;i<=n;i++){
			s+=i;
			tmp=b*s;
			if(tmp<=m) continue;
			else{
				ans=max(ans,i-1);
				break;
			}
		}
		cout<<ans;
	}
	else{
		for(int i=2;i<=n;i++){
		c[i]=a[i]-a[i-1];
	    }
	    for(int i=1;i<=n;i++){
		    tmp=0;
		    for(int j=i+1;j<=n;j++){
			    tmp+=c[j]*(j-i);
			    if(tmp<=m) continue;
			    else{
				    v=j-i;
				    ans=max(ans,v);
				    break;
			    }
		    }
	    }
	    cout<<ans;
	}
	return 0;
}
