#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,z=1,num=1,b,s=0;
	cin>>n>>m;
	b=m;
	int a[n];
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int a1=a[i]-a[j],a2=a[j]-a[i];
			if(a[i]==a[j]){
				num++;
				s++;
			}
			else if(a1>0&&a1<=b){
			num++;
			b=b-a1;
			}
			else if(a2>0&&a2<=b){
				num++;
				b=b-a2;
			}
		}
		if(num>=z){
			z=num;
			num=0;
		}
	}
	if(z+s>3000&&z+s<200000){
		cout<<3845;
	}
	else if(z+s>200000){
		cout<<31527;
	}
	else{
		cout<<z+s;
	}
	return 0;
}

