#import <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string s;
	int a[200000];
	cin>>n;
	for(int i=0;i<n;i++){

		char c;
		cin>>a[i]>>c;

		s=s+c;
		}



	long long h=0;
	long long w=0;
	for(int i=0;i<=n;i++){
		w+=a[i];
	}
if(n%2==0){
	for(int i=0;i<w/2;i++){
		if(a[i]==a[n-i]&&s[i]==s[n-i]){
			continue;
		}else if(s[i]==s[n-i]){
			if(s[i]==s[n-i-1]){
				continue;
			}else{
				h+=abs(a[n-i]-a[i]);
			}

		}
		else{
			h+=a[n-i];
		}
	}
}else{
	for(int i=0;i<w/2-1;i++){
		if(a[i]==a[n-i]&&s[i]==s[n-i]){
			continue;
		}else if(s[i]==s[n-i]){
			if(s[i]==s[n-i-1]){
				continue;
			}else{
				h+=abs(a[n-i]-a[i]);
			}

		}
		else{

			h+=a[n-i]+(a[i]-a[n-i]);
		}
	}

}


		cout<<h;



	return 0;

}
