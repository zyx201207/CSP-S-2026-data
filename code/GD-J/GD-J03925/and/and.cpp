#include<bits/stdc++.h>
using namespace std;
int a[200010];
string er[200010],d[200010];
bool cmp(string a,string b){
	return a>b;
}
void zhuan(int a,int i){//µ¹Ðò¶þ½øÖÆ 
	while(a>0){
		if(a%2==0){
			er[i]+="0";
		}else{
			er[i]+="1";
		}
		a/=2;
	}
}
string yu(string a,string b){
	string t;
	int n=min(a.size(),b.size());
	for(int i=0;i<n;i++){
		//cout<<a[i]<<' '<<b[i]<<endl;
		//cout<<a[i]=='0'||b[i]=='0'<<endl;
		if(a[i]=='0'||b[i]=='0'){
			t+='0';
		}else{
			t+='1';
		}
	}
	//cout<<t;
	
}
int zhuanhui(string t){
	int sum=0;
	int n=t.size();
	for(int i=0;i<n;i++){
		sum+=(t[i]-'0')*pow(2,i);
	}
	return sum;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	string a;
	cout<<a;
	int n,m,sum=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(m!=1){
			zhuan(a[i],i);
		}
		
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			if(a[i]>sum){
				sum=a[i];
			}
		}
		cout<<sum;
		return 0;
	}
	if(m==n){
		string t;
		for(int i=0;i<n;i++){
			t=yu(t,er[i]);
		}
		sum=zhuanhui(t);
		cout<<sum;
		return 0;
	}
	if(m==2){
		for(int i=0;i<n;i++){
			for(int j=i;j<n;j++){
				sum=max(sum,zhuanhui(yu(er[i],er[j])));
			}
		}
		cout<<sum;
		return 0;
	}
	for(int i=0;i<n;i++){
		string t=er[i];
		int siz=t.size();
		for(int j=siz-1;j>=0;j--){
			d[i]+=t[j];
		}
	}
	sort(d,d+n,cmp);
	string t;
	for(int i=0;i<m;i++){
		t=yu(t,er[i]);
	}
	sum=zhuanhui(t);
	cout<<sum;
	return 0;
	
} 
