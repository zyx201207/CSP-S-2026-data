#include <bits/stdc++.h>
using namespace std;
long long n,s;
long long a[200001];
string b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i = 0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	int l = 0,r = n-1;
	while(l<=r){
		if(b[l]!=b[r]&&a[l]!=a[r]&&a[l]<a[r]){
			s+=a[l];
			a[r]-=a[l];
			l++;
		}
		else if(b[l]!=b[r]&&a[r]==a[l]){
			s = s+a[r];
			l++;
		}
		else if(b[l]==b[r]&&a[r]==a[l])l++,r--;
		else if(b[l]==b[r]&&a[r]>a[l]){
			a[r]-=a[l];
			l++;
		}
		else if(b[l]==b[r]&&a[r]<a[l]){
			a[l]-=a[r];
			r--;
		}
		else if(b[l]!=b[r]&&a[l]>a[r]){
			a[l]-=a[r];
			s+=a[r];
			r--;
		}
	}
	cout<<s;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
