#include<bits\stdc++.h>
using namespace std;
int num[2000005],biger = 0;
bool bum[2000005];
int n,m;
long long twice(int o){
	long long r = 1;
	for(int i = 1;i <= o;i++){
		r*=2; 
	}
	return r;
}
string huiwen(string p){
	for(int i = 0;i < p.size()/2;i++){
		swap(p[i],p[p.size()-i-1]);
	}
	return p;
}
string twop(int y){
	string p = "";
	while(y){
		int u = y%2;
		if(u == 1){
			p+='1';
		}
		else{
			p+='0';
		}
		y/=2;
	}
	return huiwen(p);
}
int anwe(int a,int b){//and函数 
	string a1 = twop(a), b1 = twop(b),c1;//二进制字符串 
	if(a1.size() > b1.size()){
		c1 = b1;
	}
	else{
		c1 =a1;
	}
	//cout<<a1<<' '<<b1<<'\n';
	for(int i = 1;i <= min(a1.size(),b1.size());i++){//and求二进制字符串 
		if(a1[i] == '1'&&b1[i] == '1'){
			c1[i] = '1';
		}
		else{
			c1[i] = '0';
		}
	}
	//cout<<c1<<"\n";
	long long ans = 0;//字符串求值转int 
	for(int i = 0;i < c1.size();i++){
		if(c1[i] == '1'){
			ans += twice(c1.size()-i-1);
		}
	}
	return ans;
}
void dfs(int cnt,int ce,int and1){//cnt第几个数，ce选了几个数 
	//cout<<cnt<<' '<<ce<<' '<<and1<<"\n";
	//for(int i = 1;i <= n;i++)cout<<bum[i]<<"\n";
	if(ce == m){
		biger = max(biger,and1);
		return ;
	}
	if(cnt == n)return ;
	//if(ce == 0)and1 = num[cnt];
	bum[cnt] = 1;
	dfs(cnt+1,ce+1,anwe(num[cnt],and1));//选这个数
	bum[cnt] = 0;
	dfs(cnt+1,ce,and1); 
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>num[i];
	}
	//cout<<anwe(anwe(31,15),7);
	for(int i = 1;i <= n;i++)dfs(1,1,num[i]);
	cout<<biger;
	return 0;
} 
