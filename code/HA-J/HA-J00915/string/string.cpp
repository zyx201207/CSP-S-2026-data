#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,num,cNum,mxCNum=-33550336,t=0;
	char num_c[200005]={};
	int num_cN[200005]={0};
	char cMst;
	cin>>n;
	vector<char>v;
	char c;
	for(int i=0;i<n;i++){
		cin>>num;
		cin>>c;
		num_c[i]=c;
		num_cN[i]=num;
		for(int j=0;j<num;j++){
			v.push_back(c);
		}
		mxCNum=max(mxCNum,num_cN[i]);
	}
	for(int i=0;i<n;i++){
		if(num_cN[i]==mxCNum){
			cMst=num_c[i];
			break;
		}
	}
	for(int i=0;v[i+1]!='\0';i++){
		if(v[i]==cMst){
			continue;
		}
		if(v[i]!=v[0]){
			t++;
		}
	}
	bool f=true;
	for(int i=n-1;i>=0;i--){
		if(v[i]!=v[n-i-1]){
			f=false;
		}
	}
	cout<<t;
	return 0;
}
