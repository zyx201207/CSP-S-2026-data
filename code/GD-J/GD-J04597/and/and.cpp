#include<bits/stdc++.h>
using namespace std;
long long a[200500];
string b[200500],c[200500];
long long f=0;
void zhuan(long long y,long long num){
	f=0;
	while(y>0){
		b[num]+=(y%2)+'0';
		y/=2;
		f++;
	}
}
long long zhuan2(string w,long long num){
	long long shu=0;
	for(long long i=0;i<num;i++){
		shu+=pow(2,i)*(w[i]-'0');
	}
	return shu;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n,m;
	cin>>n>>m;
	if(m==n){
		cin>>a[1];
		int iii=a[1];
		for(long long i=2;i<=n;i++){
			cin>>a[i];
			iii=iii&a[i];
		}
		cout<<iii;
		return 0;
	}
	long long max_num=0;
	for(long long i=1;i<=n;i++){
		
		cin>>a[i];
		zhuan(a[i],i);
		
		max_num=max(max_num,f);
	}
	long long cnt=0;
	long long u=n,p=1;
	bool f=true;
	for(long long x=1;x<=max_num;x++){
		long long cnt=0;
		for(long long i=1;i<=n;i++){
			if(b[i][max_num-x]=='1'){
				
			}else if(u>m){
				b[i]="";
				u--;
			}
			if(u==m){
				for(long long i=1;i<=n;i++){
					if(b[i]!=""){
						c[p]=b[i];
						p++;
					}
				}
				break;
				f=false;
			}
			if(!f){
				break;
			}
		} 
		if(!f){
			break;
		}
	
	}
	if(f){
		for(long long i=1;i<=n;i++){
			if(b[i]!=""){
				c[p]=b[i];
				p++;
			}
		}
	}
	long long count2=zhuan2(c[1],max_num);
	for(long long i=2;i<p;i++){
		long long da=zhuan2(c[i],max_num);
	
		count2=count2&da;
	}
	cout<<count2;
	
	
	
	
	
	
	
	return 0;
} 
