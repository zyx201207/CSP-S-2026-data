#include<bits/stdc++.h>
using namespace std;
long long n,cnt;
struct f{
	int a;
	char b;
}s[1000010],l[1000010],r[1000010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>s[i].a>>s[i].b;
		cnt+=s[i].a;
	}
	if(cnt%2!=0){
		for(int i=cnt/2;i<cnt;i++){
			long long g=s[i].a;
			char h=s[i].b;
			s[i].a=s[i+1].a;
			s[i].b=s[i+1].b;
			s[i+1].a=g;
			s[i+1].b=h;
		}
		cnt-=1;
	}int kq=0;
		long long ans1=cnt/2,ans=cnt/2,slr=0,kk,pp;
		for(long long i=0,j=0;i<ans1;i++){
			if(s[i].a<ans){
				ans-=s[i].a;
				l[j].a=s[i].a;
				l[j].b=s[i].b;
				j++;
			}else{
				l[j].a=ans;
				l[j].b=s[i].b;
				slr=s[i].a-ans;
				r[0].a=slr;
				r[0].b=s[i].b;
				kq=1;
			}
			kk=j;
		}
		if(kq==0){
			r[0].a=s[ans1].a;
			r[0].b=s[ans1].b;
		}
		for(long long i=ans1+1,j=1;i<cnt;i++){
			r[j].a=s[i].a;
			r[j].b=s[i].b;
			j++;
			pp=j;
		}
		long long k=0;
		for(long long i=0,j=pp;i<kk,j>=0;){
			if(l[i].b!=r[j].b){
				if(l[i].a>r[j].a){
					j--;
					k+=r[j].a;
					l[i].a-=r[j].a;
				}else if(l[i].a<r[j].a){
					i++;
					k+=l[i].a;
					r[j].a-=l[i].a;
				}else{
					i++;
					j--;
					k+=r[j].a;
				}
			}
		}
		cout<<k<<endl;
	
	return 0;
}
