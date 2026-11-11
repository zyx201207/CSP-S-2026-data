#include <bits/stdc++.h>
using namespace std;
struct bt{
	string a;//二进制数 
};
bt s[200005];
int cmp(bt e,bt f){
	return e.a>f.a;//排序 
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		long long x;
		cin>>x;//原数 
		string b;//二进制数（倒序） 30位 
		for(int j=0;j<=20;j++){//转进制为二 
			b+=x%2+'0'; 
			x/=2;
		}
		for(int j=20;j>=0;j--){
			s[i].a+=b[j];//存入二进制数 
		}
	} 
	for(int i=0;i<=20;i++){//每一位分别位与 
		sort(s+1,s+1+n,cmp);//排序 
		if(s[m].a[i]!='1'){//若此位 1 的个数不够 
			for(int j=1;j<=m;j++){//清空所有数此位上的 1 
				if(s[j].a[i]=='0'){
					break;
				}
				s[j].a[i]='0';
			}
		}
	}
	
	sort(s+1,s+1+n,cmp);//排序  第一个即最好情况 
	long long ans=0;
	for(int i=0;i<=20;i++){//遍历二进制的每一位 
		ans=ans*2+s[1].a[i]-'0';//转为十进制 
	}
	cout<<ans;
	return 0;
} 
//桃李春风一杯酒 江湖夜雨十年灯 
