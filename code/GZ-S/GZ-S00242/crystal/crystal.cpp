//GZ-S00242 贵州师范大学云岩实验中学 王又可 
#include<bits/stdc++.h>
using namespace std;
int n,m,s,s1,s2,s3;
int a[500005];
int b[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int j=0;j<n-1;j++){
		for(int i=1;i<n;i++){
			if(a[i]<a[i-1]){
				int c=a[i-1];
				a[i-1]=a[i];
				a[i]=c;			
			}
		} 
	}
	for(int i=0;i<n;i++){
		if(a[i]==a[i+1]){
			s3++;
		}
	}
	if(n%2==0){
		s=n/2;
	}else{
		s=n/2+1;
	}
	for(int i=0;i<n;i++){
		if(a[i]<a[s]){
			b[i]=a[s]-a[i];
		}
	}
	for(int i=0;i<s;i++){
		s1+=b[i];
		s2++;
	}
	cout<<s2+s3;
	return 0;
}
