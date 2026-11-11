#include<bits/stdc++.h>
using namespace std;
struct stu{
	int ws;string s;
}sa[200005];
string ss;long long n,m,a[200005],now,ys,cnt,ans,lbz;long long N=1073741824;string b[200005],c[200005];
pair<int,string>lld10_lld2(long long a){
	ss="";
	long long jz=N,bl=0,js=0,yunx=0;
	while(jz){
		if(bl){
			if(jz>a){
				js++;
				ss+='0';
			}else{
				js++;
				a-=jz;
				ss+='1';
			}
		}else{
			if(jz<=a){
				js++;
				a-=jz;
				ss+='1';
				bl=1;
			}else{//cout<<31-yunx<<" "<<lbz<<endl;
				if(lbz!=0&&31-yunx<=lbz){
					
					ss+='0';
				}
				yunx++;
			}
		}
		jz/=2;
	}
	return {js,ss};
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	//cout<<n<<"!";
	sort(a+1,a+1+n,greater<long long>());
	for(int i=1;i<=n;i++){
		pair<int,string> cun=lld10_lld2(a[i]);
		sa[i].ws=cun.first;
		sa[i].s=cun.second;
		if(lbz==0){
			lbz=sa[i].ws;
		}
		if(sa[i].ws==sa[i-1].ws){
			now++;
		}else{
			if(now>=m&&ys==0){
				ys=i-now;
				break;
			}else{
				now=1;
			} 
		}
	}
	if(now>=m&&ys==0){
			ys=n-now+1;
	} 
	if(now<m){
		ys=1,now=n;
	}
	for(int j=1;j<sa[ys].s.size();j++){
//	cout<<j<<endl;
//	for(int i=1;i<ys+now;i++){
//		if(sa[i].s!=""){
//			cout<<sa[i].s<<endl;
//		}
//	}
		long long noww=0;
		//cout<<endl;
		//cout<<j<<endl;
		for(int i=1;i<ys+now;i++){
			if(sa[i].s!=""&&sa[i].s[j]=='1'){
				noww++;
			};
		}
	//	cout<<noww<<endl;
		if(noww>=m){
			for(int i=1;i<ys+now;i++){
				if(sa[i].s!=""&&!(sa[i].s[j]=='1')){
					sa[i].s="";
				}
			}
		}
	
	}
		
	for(int i=1;i<ys+now;i++){
		if(sa[i].s!=""){
			long long lj=1;cnt=0;
			for(int j=sa[i].s.size()-1;j>=0;j--){
				cnt+=lj*(sa[i].s[j]-'0');
				lj*=2;
			}
			if(ans==0)ans=cnt;
			ans&=cnt;
		}
	}
	cout<<ans;
	return 0;
} 



