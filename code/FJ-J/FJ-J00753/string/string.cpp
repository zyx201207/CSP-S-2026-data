#include <iostream>
#include <cstdio> 
using namespace std;
const int N = 1e6+10;
int str[N],coun[N];
int main(int argc, char** argv) {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin>>n;
	long long ans = 0;
	for(int i=0;i<n;i++){
		char c;
		cin>>coun[i]>>c;
		str[i] = c;
	}
	int st=0,end = n-1;
	while(st<end){
		int minx = min(coun[end],coun[st]);
		if(str[end] != str[st]){
			ans+=minx;
		}
		coun[end]-=minx;
		coun[st]-=minx;
		if(coun[st]==0){
			st++;
		}
		if(coun[end]==0){
			end--;
		}
	}
	cout<<ans;
	return 0;
}