#include<bits/stdc++.h>
using namespace std;
long long sum=0;
long long cnt=1;
long long a[200005];
char b[200005];
char s[1000000000];
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s[cnt]=b[i];
			cnt++;
		}
	}
	for(int i=1;i<=cnt;i++){
		if(s[i]==s[1]){
			sum++;
		}
		if(sum==cnt-1){
			cout<<"0";
			return 0;
		}
		else{
			sum=0;
			if(cnt%2==0){
				for(int i=1;i<=cnt/2;i++){
					if(s[i]!=s[cnt+1-i]){
						sum++;
					}
				}
			}
			if(cnt%2==1){
				for(int i=1;i<=(cnt+1)/2;i++){
					if(s[i]!=s[cnt+1-i]){
						sum++;
					}
				}
			}
		}
	}
	cout<<sum;
	return 0;
}
