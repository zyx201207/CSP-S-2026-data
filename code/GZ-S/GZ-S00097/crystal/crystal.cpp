//GZ-S00097 安顺市第二高级中学 郭竞琦 
#include<bits/stdc++.h>
using namespace std;
const int Max=5e5+7;
int n;
long long m,a[Max],ans=1,bl;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<n-1;i++){
		if(a[i+1]-a[i]!=a[i+2]-a[i+1]){
			bl=1;
			break;
		}
	}
	if(bl){
		for(int i=n;i>1;i--){
			int z=1,mm=m;
			for(int j=i-1;j>=1;j--){
				if(mm>=a[i]-a[j]){
					z++,mm-=a[i]-a[j];
					if(j==1&&mm%n!=0){
						z--;
					}
				}
			}
			if(z>ans){
				ans=z;
			}
		}
	}
	else{
	    for(int i=n-1;i>=1;i--){
	    	if(m>=a[n]-a[i]){
		    	m-=a[n]-a[i];
		    	ans++;
			    if(i==1&&m%n!=0){
				    ans--;
			    }
	    	}
    	}
    }
	cout<<ans;
	return 0;
}
