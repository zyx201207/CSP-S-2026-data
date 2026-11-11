#include<bits/stdc++.h>
using namespace std;
int main(){
	int c,t;
	cin>>c>>t;
	for(int f=1;f<=t;f++){
		int n,d,a[200003],s=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		a[n+1]=a[n]-a[1];
		for(int i=a[n+1];i>d;i--){
			if(i<=d*2){
				s+=i-d+1;
			}
		}
		cout<<s/2<<endl;
	}
	return 0;
}
