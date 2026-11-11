#include<bits/stdc++.h> 
using namespace std;
bool small;
int n;
long long num;
string all,nums;
int huiwen(string a){
	int ans=0;
	string aq,ah;
	//aq是从前向一半的 ah是由后往一半的 (ah在奇数时多1） 
	for(int i=0;i<=floor(double(a.size()/2))-1;i++)
		aq+=a[i];
	for(int i=a.size();i>floor(a.size()/2);i--)
		ah+=a[i-1];
	for(int i=0;i<ah.size();i++){
		if(aq[i]==ah[i])
			continue;
		else
			ans++;//比较，出现不相等的加一 
	}
	if(a.size()%2==1) ans-=1;//删掉奇数多的1（中间的那一个） 
	return ans;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>num>>nums;
		for(int j=0;j<num;j++) //由于time限制 13 ～ 16，22 ～ 25的测试点无法通过 （加10的九次方时for循环时间超限 ） 
			all+=nums;
	}
    cout<<huiwen(all);

	
	return 0;
	}
