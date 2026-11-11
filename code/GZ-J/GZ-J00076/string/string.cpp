//GZ-J00076 贵阳市第三中学 吴钰辉 
#include<bits/stdc++.h>
using namespace std;
long long n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	vector<long long>a(n);
	vector<char>b(n);
	string s;
	for(long long i=0;i<n;i++){
		cin>>a[i]>>b[i];
		for(long long j=a[i];j>0;j--)s+=b[i];
	}
	long long l=0,r=s.size()-1,sum=0;
	while(l<=r){
		if(s[l]!=s[r])sum++;
		l++;
		r--;
	}
	cout<<sum;
    return 0;
}
