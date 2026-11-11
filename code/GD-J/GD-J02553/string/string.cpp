#include<bits/stdc++.h>
using namespace std;
string S;
long long a[200005];
long long cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,len=0;
	char ts=' ';
	cin>>n;
	if(n<=3000){
		for(int i=1;i<=n;i++){
			cin>>a[i]>>ts;
			if(a[i]>=60) {
				cout<<cnt/2;
				return 0;
			}
			len+=a[i];
			for(int j=1;j<=a[i];j++) S+=ts;
			//cout<<S<<endl;
		}
		//cout<<len<<endl;
		for(int i=0;i<len;i++){		
			if(S[i]!=S[len-i-1]) {
				cnt++;
				//cout<<cnt<<" "<<i<<endl;
			}
			
		}
	}
	cout<<cnt/2;
	return 0;
}
