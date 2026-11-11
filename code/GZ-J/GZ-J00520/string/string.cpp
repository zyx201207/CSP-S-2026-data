//准考证:GZ-J00520 学校:龙里县民族完全中学 姓名:李玮辰 
#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	string a="";
	int n,x; char c;
	cin>>n;
	while(n--){
		cin>>x>>c;
		while(x--)a+=c;
	}
	int h=0;
	int i=0;
	int z=a.size();
	while(i<(z>>1)){
		if(a[i]!=a[z-i-1])h++;
		i++;
	}
	cout<<h;
	return 0;
}
