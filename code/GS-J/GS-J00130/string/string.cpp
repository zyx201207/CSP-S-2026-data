#include <bits/stdc++.h>
using namespace std;

int n;
long long m=0;
struct a{
	long long Num;
	string g;
}p[10005];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>p[i].Num>>p[i].g;
	}
	long long S=0;
	int l=1,r=n;
	bool flag;
	while(l<r){
		int S=min(p[l].Num,p[r].Num);
		if (p[l].g==p[r].g){
			flag=false;
		}
		else{
			flag=true;
		}
		if (p[l].Num==p[r].Num){
			p[r].Num=0;
			p[l].Num=0;
			l++;
			r--;
		}
		else if (p[l].Num>p[r].Num){
			p[l].Num=p[l].Num-p[r].Num;
			p[r].Num=0;
			r--;
		}
		else{
			p[r].Num=p[r].Num-p[l].Num;
			p[l].Num=0;
			l++;
		}	
		if (flag){
			m+=S;
		}
	}
	cout<<m;
	return 0;
}
