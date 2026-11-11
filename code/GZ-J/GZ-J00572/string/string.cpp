//贵阳市第十八中学 刘文浩 GZ-J00572
#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int sum=0;
	cin>>n;
	for(int i=0;i<n;i++){
		int num;
		string c;
		cin>>num>>c;
		for(int i=sum;i<sum+num;i++)
			s+=c;
		sum+=num;
	}
	sum=0;
	int l=0,r=s.size()-1;
	while(l<r){
		if(s[l]!=s[r]) sum++;
		l++,r--;
	}
	cout<<sum;
	return 0;
}
