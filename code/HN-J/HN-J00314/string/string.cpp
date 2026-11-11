#include<bits/stdc++.h>
using namespace std;
int n,a[200005],m,p,i,j;
long long lg,ans=0;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
//		for(int j=0;j<a;j++)
//			s[j+lg]=c;
//		lg+=a;
//		cout<<a[i]<<' '<<c[i]<<endl;
	}
	i=0;j=n-1;
	for(int k=0;;k++){
		p=a[i]-a[j];
//		cout<<p<<endl;
//		cout<<a[i]<<' '<<c[i]<<endl;
//		cout<<a[j]<<' '<<c[j]<<endl;
		if(i>=j) break;
		if(p>0 && c[i]==c[j]){
			a[i]-=a[j];
			j--;
		}
		else if(p<0 && c[i]==c[j]){
			a[j]-=a[i];
			i++;
		}
		else if(p<0 && c[i]!=c[j]){
			a[j]-=a[i];
			ans+=a[i];
			i++;
		}
		else if(p>0 && c[i]!=c[j]){
			a[i]-=a[j];
			ans+=a[j];
			j--;
		}
		else if(p==0 && c[i]!=c[j]){
			ans+=a[i];
			i++;
			j--;
		}
		else if(p==0 && c[i]==c[j]){
			i++;
			j--;
		}
//		if(s[i]!=s[lg-i-1]) ans++;
//		cout<<s[i]<<' '<<s[lg-i]<<endl;
//		cout<<ans<<endl;
	}	
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
