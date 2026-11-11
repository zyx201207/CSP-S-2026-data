#include<bits/stdc++.h>
using namespace std;
long long n,m,len,ans,maxx=-1,pos;
long long a[200005],B[200005],b,num;
long long sum[200005];
string s[200005],ans1;
string change(int n){
	string s="";
	long long cnt=0;
	while(n!=0){
		cnt++;
		int a=n%2;
		char c;
		c='1'+a-1;
		s=c+s;
		n/=2;
	}
	len=max(len,cnt);
	return s;
}
long long ANS(string s){
	int x=s.size()-1;
	long long num=0;
	int cnt=0;
	for(x;x>=0;x--){
		num+=(s[x]-'0')*pow(2,cnt);
//		cout<<num<<' '<<pow(2,cnt)<<endl;
		cnt++;
	}
	return num;
}
bool cmp(int a,int b){
	return a>b;
}
void dfs(int x,int f){
	if(x==m+1){
		ans=max(ans,num);
		return;
	}
	if(x==1){
		for(int i=f;i<=n;i++){
			num=a[i];
			dfs(x+1,i+1);
			num=0;
		}
	}
	else{
		for(int i=f;i<=n;i++){
			long long io=num;
			num=num&a[i];
			dfs(x+1,i+1);
			num=io;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]%2!=1){
			b=1;
		}
	}
	if(n==m){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}
	if(b==0){
		sort(a+1,a+1+n,cmp);
		cout<<a[m];
		return 0;
	}
	
	if(n<=2000){
		dfs(1,1);
		cout<<ans;
		return 0;
	}
	
	
	for(int i=1;i<=n;i++){
		s[i]=change(a[i]);
//		cout<<s[i]<<endl;
	}
//	cout<<endl;
	for(int i=1;i<=n;i++){
		while(s[i].size()<=len-1){
			s[i]="0"+s[i];
		}
	}
	for(int i=1;i<=n;i++){
//		cout<<s[i]<<endl;
	}
//	cout<<endl;
	len-=1;
	for(int i=0;i<=len+1;i++){
		int io=0;
		for(int j=1;j<=n;j++){
			if(s[j][i]=='1'){
				io++;
				B[j]=1;
			}
//			cout<<s[j][i]<<' '<<io<<endl;
		}
		if(io>=m){
			maxx=io;
			pos=i;
			break;
		}
	}
//	cout<<maxx<<' '<<pos<<endl;
	if(maxx<m){
		cout<<0;
		return 0;
	}
	ans1="1";
//	cout<<len<<endl;
	for(int i=pos;i<=len-1;i++){
		int io=0;
		for(int j=1;j<=n;j++){
			if(i==pos){
				if(B[j]==1){
					if(s[j][i+1]=='1'){
						io++;
						sum[j]=1;
					}
				}
			}
			else{
				if(s[j][i+1]=='1'){
					io++;
				}
			}
		}
//		for(int j=1;j<=n;j++){
//			cout<<sum[j]<<' ';
//		}
//		cout<<endl;
		if(io>=m){
			ans1+="1";
		}
		else{
			ans1+="0";
		}
		for(int j=1;j<=n;j++){
			B[j]=sum[j];
		}
		memset(sum,0,sizeof(sum));
	}
	cout<<ANS(ans1);
	return 0;
}
