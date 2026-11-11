//GZ-S00227 敬涵晓 遵义市第十二中学 
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	string s;
	for(int i=0;i<n;i++){
	cin>>a[i];
	}
	sort(a,a+n);
	for(int i=1;i<=n;i++){
		if(a[i]-a[0]<m){
			s[i]=a[i];
		}
	}
	int zs=0;
	int z=s.size();
	for(int i=z -1;i>=0;i--){
		if((s[z]-s[i])+(s[z]-s[i-1])<=m){
			zs++;
		}
	}
	cout<<zs<<endl;
	return 0;
	fclose(stdin);
	fclose(stdout);
}

