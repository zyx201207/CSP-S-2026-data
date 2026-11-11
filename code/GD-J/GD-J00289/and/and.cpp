#include<bits/stdc++.h>
using namespace std;

int n,m;
long long a[100],ans=0,b[200005];
string c[200005];

//a相应位的1数量，b原始数据，c倒序2进制

int main(){
	freopen("and.in","r",stdin);
	freopen("and.ans","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int tmp;
		cin>>tmp;
		b[i] = tmp; 
		string wei;
		while(tmp){
			wei += tmp%2?'1':'0';
			tmp /= 2;
		}
		for(int i=0;i<wei.length();i++){
			if(wei[i] == '1'){
				a[i] ++;
			}
		}
		c[i] = wei;
	}
	bool zui = 1;
	int zi;
	for(int i=0;i<100;i++){
		if(a[i]>m){
			zui =0;
			zi=i;
		}
	}
	if(zui){
		cout<<0;
		return 0;
	}
	while(!zui){
		zui = 1;
		for(int i=0;i<100;i++){
			if(a[i]>=m){
				zui =0;
				zi=i;
			}
		}
		if(zui){
			break;
		}
		a[zi] = 0;
		for(int j=0;j<n;j++){
			if(b[j]!= 0&&(c[j].length()<=zi||c[j][zi]=='0')){
				b[j] = 0;
				for(int k=0;k<c[j].length();k++){
					if(c[j][k]=='1'){
						if(a[k] > 0) a[k] --;
					}
				}
			}
		}
		ans+=(1<<zi);
	}
	
	cout<<ans;
	return 0;
}
