#include<bits/stdc++.h>
using namespace std;
vector<int> vec;
int c1to5(int n,int a,int m,int sum){
	if(m==0){                //终止条件 
		return sum;
	}
	int max=0;               //最大值 
	for(int i = a+1;i<n;i++){
		int s=sum&vec[i];
		int d=c1to5(n,i,m-1,s);
		if(max<d)max=d;
	}
	return max;
}
void solve_1to5(int n,int m){//1~5
	for(int i = 1;i<=n;i++){
		int a;cin>>a;
		vec.push_back(a);
	}
	int sum=1;
	for(int i = 1;i<=21;i++)sum*=2;
	sum=sum-1;               //定义一个2^21-1的sum,方便进行按位与
	cout<<c1to5(n,-1,m,sum);
}
void solve_6(int n){         //6号
	int max=-1;
	for(int i = 1;i<=n;i++){
		int a;
		cin>>a;
		if(a>max)max=a;
	}
	cout<<max;
}
void solve_7(int n){         //7号 
	int sum=1;
	for(int i = 1;i<=21;i++)sum*=2;
	sum=sum-1;               //定义一个2^21-1的sum,方便进行按位与 
	for(int i = 1;i<=n;i++){
		int a;
		cin>>a;
		sum=sum&a;
	}
	cout<<sum;
}
void solve_8to10(int n){     //8~10号用枚举法 
	int a=0;
	for(int i = 1;i<=n;i++){
		int c;cin>>c;
		vec.push_back(c);
		if(c=1048576)a++;//统计2^20的个数 
		if(a>=2){
			cout<<1048576;
			return;
		}
	}
	sort(vec.begin(),vec.end());
	int a1=vec.back();
	vec.pop_back();
	int a2=vec.back();
	a=a1&a2;//a=最后两位按位与 
	cout<<a;
}
void solve_16_17(int n,int m){//16 17用暴力枚举 
	int a[5]={0};
	for(int i = 0;i<n;i++){
		a[vec[i]]++;
	}
	if(a[4]>=m)cout<<4;
	else if(a[3]>=m)cout<<3;
	else if(a[3]+a[2]>=m)cout<<2;
	else if(a[3]+a[1]>=m)cout<<1;
	else cout<<0;
}
void solve_11to20(int n,int m){
	bool fo=true,t10=true;
	for(int i = 1;i<=n;i++){
		int a;cin>>a;
		if(a>4)fo=false;
		if(a>1024)t10=false;
	}
	if(fo){
		solve_16_17(n,m);
	}
	else if(t10){
		solve_18_19(n,m);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(n<=20)solve_1to5(n,m);
	else if(n<=2000){
		if(m==1)solve_6(n);
		else if(m==n)solve_7(n);
		else solve_8to10(n);
	}
	else{
		solve_11to20(n,m);
	}
	return 0;
}
