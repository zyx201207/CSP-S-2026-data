#include <bits/stdc++.h>
using namespace std;
long long num[200005];
string s,s1,s2,s3;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int sum=0;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
	//	sum+=x;
		char zimu;
		cin>>zimu;
		num[i-1]+=x;//об╠Й1 
		s+=zimu;
	}

	int l=s.size();

		for(int i=0;i<l/2;i++){
			s1+=s[i];
		}
		for(int i=l/2;i<l;i++){
			s2+=s[i];
		}
	
//	cout<<num[2+l/2]<<endl;
	cout<<s1<<endl<<s2;
long long cnt=0;
	
		for(int i=0;i<s1.size();i++){
			if(s1[i]!=s2[i]){
				cnt+=num[i+l/2];
			
			}
		}
	
	cout<<cnt;

	return 0;
}
