//GZ-S00297 ¸£ÈªÖÐÑ§ ½ðÊ¥¶÷ 
#include<bits/stdc++.h>
using namespace std;
long long a,b,sj[500000];

int main(){
	freopen("crystal.cpp","r",stdin);
	freopen("crystal.cpp","w",stdout);
	cin>>a>>b;
	int ll=b,ok=0;
	for(int i=0;i<a;i++){
		cin>>sj[i];
	}
	sort(sj, sj+a);
	for(int i=b;i>0;i--){
		sj[0]++;
		sort(sj, sj+a);
	}
	for(int i=0;i<a;i++){
		if(sj[i]==sj[i+1])ok++;
	}
	cout<<ok+1;
}
