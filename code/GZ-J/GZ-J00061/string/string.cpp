// 准考证号：GZ-J00061  姓名： 孙连友
#include<iostream>
#include<string>
using namespace std;
	int a[200004];
	string s[200055];
void solve(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		cin>>s[i];
	}
	long long few=a[0];
	long long hui=a[n-1];
	long long ans=0;
	long long b=0;
	int i=0;
	int j=n-2;
	do{
		if(few>=hui){
			if(s[i]!=s[j+1]){
				ans+=(hui-b);
				b=hui;
				hui+=a[j];
				j--;
			}else{
				b=hui;
				hui+=a[j];
				j--;
			}
		}
		if(few<hui){
			if(s[i]!=s[j+1]){
				ans+=(few-b);
				b=few;
				few+=a[i];
				i++;
			}else{
				b=few;
				few+=a[i];
				i++;
			}
		}
	}while(i<=j);
	printf("%lld\n",ans);
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	solve();
	fclose(stdout);
	return 0;
}
