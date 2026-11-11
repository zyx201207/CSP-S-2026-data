#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005];
char c[200005];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ans=0;
	bool f=0;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> c[i];
		if(a[i]>500){
			f=1;
		}
	}
	if(f==0){
		string s="";
		int x,l;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i];j++){
				s+=c[i];
			}
		}
		l=s.size();
		for(int i=0;i<l/2;i++){
			if(s[i]!=s[l-i-1]){
				ans++;
			}
		}	
	}else{
		for(int i=1,j=n;j!=i;){
			if(c[i]==c[j]){
				if(a[i]>a[j]){
					a[i]-=a[j];
					j--;
				}else if(a[j]>a[i]){
					a[j]-=a[i];
					i++;
				}else{
					i++;
					j++;
				}
			}else{
				if(a[i]>a[j]){
					ans+=a[j];
					a[i]-=a[j];
					j--;
				}else if(a[j]>a[i]){
					ans+=a[i];
					a[j]-=a[i];
					i++;
				}else{
					ans+=a[i];
					i++;
					j++;
				}
			}
		}		
	}
	cout << ans << endl;
	return 0;
}
