//GZ-J00420 贵阳市第三实验中学 陈典伸
#include<bits/stdc++.h>
using namespace std;
struct shulie{
	long long a;
	string s;
};
long long n;
string S;
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	shulie v[n];
	for(long long i=0;i<n;i++){
		cin>>v[i].a>>v[i].s;
		for(long long j=0;j<v[i].a;j++){
			S+=v[i].s;
		} 
	}
	long long m=S.size();
	if(n%2==0){
		for(long long i=0;i<m/2;i++){
			if(S[i]!=S[m-i-1]){
				ans++;
			}
		}
	}else{
		for(long long i=0;i<(m-1)/2;i++){
			if(S[i]!=S[m-i-1]){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
