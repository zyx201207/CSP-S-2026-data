//GZ-J00289 周林学校 肖杭 
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a[200005],f1=1,f2,c=0;
	char v[200005];
	cin>>n;
	f2=n;
	for(int i=1;i<=n;i++)cin>>a[i]>>v[i];
	while(f2>f1){
		if(a[f2]<a[f1]){
			if(v[f1]!=v[f2])c+=a[f2];
			a[f1]=a[f1]-a[f2];
			f2--;
		}
		else {
	    	if(a[f2]>a[f1]){
			    if(v[f1]!=v[f2])c+=a[f1];
		    	a[f2]=a[f2]-a[f1];
	    		f1++;
	    	}
		    else {
		    	if(v[f1]!=v[f2])c+=a[f2];
		    	f1++;
		    	f2--;
		    }	
		}
	}
	cout<<c;
	return 0;
}

