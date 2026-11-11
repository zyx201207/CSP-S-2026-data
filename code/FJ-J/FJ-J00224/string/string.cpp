#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const int N=1e5+10;
ll n,len,sum,f10000,f5000,f1000,f500,f100,f50,f10,f5,f2;
string s;
struct node{
	int x;
	char c;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	s+=' ';
	cin>>n;
	for(int i=1;i<=n;i++){
		ll x;
		char c;
		cin>>x>>c;
		if(x%10000!=0) f10000=1;
		if(x%5000!=0) f5000=1;
		if(x%1000!=0) f1000=1;
		if(x%500!=0) f500=1;
		if(x%100!=0) f100=1;
		if(x%50!=0) f50=1;
		if(x%10!=0) f10=1;
		if(x%5!=0) f5=1;
		if(x%2!=0) f2=1;
		a[i].x=x;
		a[i].c=c;
	}
	for(int j=1;j<=n;j++){
		if(!f10000){
			for(int i=1;i<=a[j].x/10000;i++) s+=a[j].c;
			len+=a[j].x/10000;
		}else if(!f5000){
			for(int i=1;i<=a[j].x/5000;i++) s+=a[j].c;
			len+=a[j].x/5000;
		}else if(!f1000){
			for(int i=1;i<=a[j].x/1000;i++) s+=a[j].c;
			len+=a[j].x/1000;
		}else if(!f500){
			for(int i=1;i<=a[j].x/500;i++) s+=a[j].c;
			len+=a[j].x/500;
		}else if(!f100){
			for(int i=1;i<=a[j].x/100;i++) s+=a[j].c;
			len+=a[j].x/100;
		}else if(!f50){
			for(int i=1;i<=a[j].x/50;i++) s+=a[j].c;
			len+=a[j].x/50;
		}else if(!f10){
			for(int i=1;i<=a[j].x/10;i++) s+=a[j].c;
			len+=a[j].x/10;
		}else if(!f5){
			for(int i=1;i<=a[j].x/5;i++) s+=a[j].c;
			len+=a[j].x/5;
		}else if(!f2){
			for(int i=1;i<=a[j].x/2;i++) s+=a[j].c;
			len+=a[j].x/10;
		}else{
			for(int i=1;i<=a[j].x;i++) s+=a[j].c;
			len+=a[j].x; 
		}
	}
	for(int i=1;i<=len/2;i++){
		if(s[i]!=s[len-i+1]) sum++;
	}
	if(!f10000) cout<<sum*10000;
	else if(!f5000) cout<<sum*5000;
	else if(!f1000) cout<<sum*1000;
	else if(!f500) cout<<sum*500;
	else if(!f100) cout<<sum*100;
	else if(!f50) cout<<sum*50;
	else if(!f10) cout<<sum*10;
	else if(!f5) cout<<sum*5;
	else if(!f2) cout<<sum*2;
	else cout<<sum;
	return 0;
}
/* 
-----------
\*ABC*****|
|*DEF*GHIJ\
\*********| 
|KLMN*OPQ*\
\*****RST*|
-----------
妨碍咱的渣渣！
给我拖出去喂斯*林！
                    		--快乐的元首 
*/
