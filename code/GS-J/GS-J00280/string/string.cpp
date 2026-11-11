#include<bits/stdc++.h>
using namespace std;
string c,hwc;
bool flag=false;
bool hwx(string m){
	string hwx;
	for(int i=m.size()-1;i>0;i--){
		hwx[i]=m[i];
		hwc[i]=hwx[i];
	}
	if(hwx==m){
		return true;
	}else{
		return false;
	}
}
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	int n,z;
	int ans=0;
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	int x[1000005];
	string y[1000005];
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
		if(z==x[i]){
			flag=true;
		}else{
			flag=false;
		}
	}
	if(n%2==0 && flag==true){
		cout<<(n%2)*x[1];
		return 0;
	}else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=x[i];j++){
				c+=y[j];
			}
		}	
	}
	if(hwx(c)==true){
		cout<<0;
	}else{
		int j=0;
		for(int i=c.size()-1;i>0;i--){
			if(hwc[i]!=c[j]){
				ans++;
				c[i]=c[j];
			}
			j++;
		}
	}
	cout<<ans;
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
