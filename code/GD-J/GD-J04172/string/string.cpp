#include<bits/stdc++.h>

using namespace std;

long long n,ans=0,k=0;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	vector<long long> a(n+1);
	vector<char> c(n+1);
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		k+=a[i];
	}
	vector<char> ch(k+1);
	int l=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			ch[l]=c[i];
			l++;
		}
	}
	if(k%2==1){
		k++;
		k/=2;
	}
	else k/=2;
	if(k%2==1){
		for(int i=1;i<k;i++){
			if(ch[k+i]==ch[k-i]){
				continue;
			}
			else{
				ans++;
			}
		}
	}
	else {
		for(int i=1;i<k;i++){
			if(ch[k+i]==ch[k-i+1]){
				continue;
			}
			else{
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
