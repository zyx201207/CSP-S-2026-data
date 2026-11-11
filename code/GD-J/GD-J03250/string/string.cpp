#include<bits/stdc++.h>
#define ll long long
using namespace std;
string a,p;
ll n,ans;
int main(){
	//优化ll数组 
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//打开文件 
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		ll num;
		char wh;
		cin>>num>>wh;
		for(int i=1;i<=num;i++){
			a+=wh;
		} 
	}if(a.size()%2==1){
		p=a;
		for(int i=0;i<=a.size()/2-1;i++){
			char q=a[i];
			p[i]=q;
		}for(int i=a.size()/2,j=i;i>=0;i--,j++){
			char q=a[i];
			p[j]=q;
		}	
	}
	for(int i=0;i<=a.size()-1;i++){
		if(p[i]!=a[i]){
			ans+=1; 
		}
	}cout<<ans;
	
	
	//关闭文件 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
