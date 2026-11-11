#include<bits/stdc++.h>
using namespace std;
long long n;
string a;
bool check(string ans){
	int flag=1;
	for(long long i=0;i<ans.size()/2;i++){
		if(ans[i]!=a[ans.size()-i-1]){
			flag=0;
		}
	}
	if(flag){
		return 1;
	}else{
		return 0;
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		long long cnt;
		cin>>cnt;
		char zm;
		cin>>zm;
		while(cnt--){
			a+=zm;
		}
	}
	if(check(a)){
		cout<<"0";
		return 0;
	}else{
		if(a.size()%2==0){
		//	cout<<a<<endl;
			long long num=0;
			for(long long i=0;i<a.size()/2;i++){
				if(a[i]!=a[a.size()-i-1]){
				//	cout<<a[i]<<" "<<i<<" "<<a[a.size()-i-1]<<" "<<a.size()-1-i<<endl;
					num++;
					a[i]=a[a.size()-i-1];
				}
			}
			cout<<num;
			return 0;
		}else{
			long long num=0;
			for(long long i=0;i<a.size()/2;i++){
				if(a[i]!=a[a.size()-i-1]){
				//	cout<<a[i]<<" "<<i<<" "<<a[a.size()-i-1]<<" "<<a.size()-1-i<<endl;
					num++;
					a[i]=a[a.size()-i-1];
				}
			}
			cout<<num;
			return 0;
		}
	}
	
	return 0;
}
