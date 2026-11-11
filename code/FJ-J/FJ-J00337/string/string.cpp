#include<bits/stdc++.h>
using namespace std;
struct p{
	long long num;
	char ch;
}c[200005],c1[200005],c2[200005];
long long a[200005],ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,sum=0,s1=0,s2=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>c[i].num;
		cin>>c[i].ch;
		sum+=c[i].num;
	}
	for(int i=1;s1<sum/2;i++){
		if(s1+c[i].num<=sum/2){
			c1[i].ch=c[i].ch;
			c1[i].num=c[i].num;
//			cout<<c1[i].ch<<" * "<<c1[i].num<<endl;
		}else{
			c1[i].ch=c[i].ch;
			c1[i].num=sum/2-s1;
//			cout<<c1[i].ch<<" *** "<<c1[i].num<<endl;
		}
		s1+=c[i].num;
	}	
	for(int i=1;s2<sum/2;i++){
		if(s2+c[i].num<=sum/2){
			c2[i].ch=c[n-i+1].ch;
			c2[i].num=c[n-i+1].num;
//			cout<<c2[i].ch<<" - "<<c2[i].num<<" "<<s2<<endl;
		}else{
			c2[i].ch=c[i].ch;
			c2[i].num=sum/2-s2;
//			cout<<c2[i].ch<<" --- "<<c2[i].num<<" "<<s2<<endl;
		}
		s2+=c[n-i+1].num;
	}
	long long j1=1,j2=1,s_1=0;
	while(s_1<sum/2){
		if(c1[j1].ch!=c2[j2].ch){
//			cout<<"AA";
			if(c2[j2].num==c1[j1].num){
				ans+=c1[j1].num;
				s_1+=c1[j1].num;
				j1++;
				j2++;
//				cout<<"1 "<<s_1<<endl;	
			}
			else if(c2[j2].num>c1[j1].num){
				ans+=c1[j1].num;
				s_1+=c1[j1].num;
				c2[j2].num-=c1[j1].num;
				j1++;
//				cout<<"2 "<<s_1<<endl;
			}
			else if(c2[j2].num<c1[j1].num){
				ans+=c2[j2].num;
				s_1+=c2[j2].num;
				c1[j1].num-=c2[j2].num;
				j2++;
//				cout<<"3 "<<s_1<<endl;
			}
		}else{
			if(c2[j2].num==c1[j1].num){
				s_1+=c1[j1].num;
				j1++;
				j2++;
			}
			else if(c2[j2].num>c1[j1].num){
				s_1+=c1[j1].num;
				c2[j2].num-=c1[j1].num;
				j1++;
			}
			else if(c2[j2].num<c1[j1].num){
				s_1+=c2[j2].num;
				c1[j1].num-=c2[j2].num;
				j2++;
			}
		}
	}
	cout<<ans;
	return 0;
} 
