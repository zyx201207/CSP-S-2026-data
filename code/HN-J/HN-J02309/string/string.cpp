#include<bits/stdc++.h>
using namespace std;
struct ab{
	long long shu;
	string s;
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,c=0,sum=0;
	cin>>n;
	ab a[n];
	vector<string> b;
	for(int i=0;i<n;i++){
		cin>>a[i].shu>>a[i].s;
		for(int j=0;j<a[i].shu;j++){
			b.push_back(a[i].s);
		}
	}
	for(int i=0;i<n;i++){
		if(i==0){
			continue;
		}
		if(a[i].s==a[i-1].s){
			if(i==n-1){
			c=1;
			cout<<"0";
			}
		}else{
			break;
		}
	}
	
	if(c!=1){
		for(int i=0;i<b.size()/2;i++){
			if(b[i]!=b[b.size()-i-1]){
				sum++;
			}
		}
	}
	cout<<sum;
	return 0;
}
