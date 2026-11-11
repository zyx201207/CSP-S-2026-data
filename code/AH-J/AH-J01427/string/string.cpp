#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200100;
struct node{
	int s=0;
	char c='a';//s为数，c为字符 
};
int n,cnt=0;
int shu[N];
char cha[N];
node a[N],b[N],c[N];
int a_z=0,b_z=0,c_z=0;
signed main(){
	freopen("string6.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>shu[i];sum+=shu[i];
		cin>>cha[i];
	}
	bool p=0,pd=1;//p判断奇数或偶数   0为偶数，1为奇数 
	if(sum%2==1) p=1; 
	sum=sum/2;
	if(p==1){
		int yu=sum+1;
		int i=1;
		while(1){
			if(yu-shu[i]>0){
				yu-=shu[i];
				i++;
			}
			else {
				shu[i]--;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if((sum-shu[i])>0&&pd==1){
			sum-=shu[i];
			a[++a_z].s=shu[i];
			a[a_z].c=cha[i];
			
		}
		else if((sum-shu[i])==0&&pd==1){
			sum-=shu[i];
			a[++a_z].s=shu[i];
			a[a_z].c=cha[i];
			pd=0;
		}
		else{
			if(pd==1){
				a[++a_z].s=sum;
				a[a_z].c=cha[i];
				b[++b_z].s=shu[i]-sum;
				b[b_z].c=cha[i];
				sum-=shu[i];
				pd=0;
					
			}
			else{
				b[++b_z].s=shu[i];
				b[b_z].c=cha[i];
			}
		}
	}
	c_z=b_z;
	for(int i=1;i<=b_z;i++){
		c[i]=b[b_z-i+1];
	}
	
//	int sa=0;
//	for(int i=1;i<=a_z;i++){
//		cout<<a[i].s<<" ";sa+=a[i].s;
//	}
//	cout<<endl;
//	cout<<endl;
//	int sb=0;
//	for(int i=1;i<=c_z;i++){
//		cout<<c[i].s<<" ";
//		sb+=c[i].s;
//	}
//	cout<<endl;
//	cout<<endl;
//	cout<<endl;
//	cout<<sa<<" "<<sb<<endl;
	
	
	int j=1;
	for(int i=1;i<=a_z;i++){
		if(a[i].s>c[j].s){
			int um=a[i].s;
//			while(1){
//				if(um-c[j].s>0){
//					if(c[j].c!=a[i].c){
//						cnt+=c[j].s;
//					}
//					um-=c[j].s;
//					j++;
//				}
//				else {
//					break;
//				}
//				if(j>c_z) break;
//				cout<<j<<endl;
//			}
//			if(c[j].c!=a[i].c) cnt+=um,cnt+=c[j].s;
//			c[j].s-=a[i].s;
//			if(c[j].s==0) j++;
//			cout<<j<<endl;
			if(c[j].c!=a[i].c) cnt+=c[j].s;
			a[i].s-=c[j].s;
			i--;
			j++;
			
		}
		else{
			if(a[i].c!=c[j].c){
				cnt+=a[i].s;
			}
			c[j].s-=a[i].s;
			if(c[j].s==0) j++;
		}
//		cout<<i<<endl;
	}
	cout<<cnt<<endl;
	return 0;
}

