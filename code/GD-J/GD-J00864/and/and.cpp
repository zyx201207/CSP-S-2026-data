#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m;
int a[N];
string s[N];
bool flag[N];
struct node{
	int x,id;
	string bit;
}S[N];
void Turn(int id,int x){
	s[id]="";
	while(x!=0){
		if(x%2==0)s[id]+='0';
		else s[id]+='1';
		x/=2;
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(m==0){
		cout<<"0";
		return 0; 
	} 
	for(int i=1;i<=n;i++){
		cin>>a[i];
		Turn(i,a[i]);
	}
	for(int i=1;i<=n;i++){
		while(s[i].size()<21)s[i]+='0';
//		S[i].bit=s[i];
		string z="";
		for(int j=s[i].size()-1;j>=0;j--){
			z+=s[i][j];
		} 
		S[i].bit=z;
		S[i].x=a[i];
		S[i].id=i;
		//cout<<z<<"\n";
	}
	int cnt=0;
	for(int i=0;i<=20;i++){//枚举第i位 从高到第 
		for(int j=1;j<=n;j++){//枚举第j个数 
			if(cnt==m)break;
			if(S[j].bit[i]=='0'||flag[S[j].id])continue;
			flag[S[j].id]=true;
			cnt++;
		}
		if(cnt==m)break;
	}
	int sum;
	vector<int> ans;
	for(int i=1;i<=n;i++){
		if(flag[S[i].id])ans.push_back(S[i].x);
	}
	sum=ans[0];
	for(int i=1;i<ans.size();i++){
		sum=(sum&ans[i]);
		//cout<<ans[i]<<"\n";
	}
	//cout<<"\n";
	cout<<sum;
} 
/*
4 2
3 15 12 12


5 3
31 3 1 15 7

6 2
1 3 2 4 5 6

6 2
4353 324534 342534 32 345 43

hack:
6 2
3545 345 3453 454 54 43523
*/
