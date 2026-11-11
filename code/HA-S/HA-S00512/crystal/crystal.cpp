/*#include<bits/stdc++.h>
using namespace std;
#define MAXN 500005

long long n,m;
long long a[MAXN],b[MAXN];
//int cnt=unique(a,a+cnt)-a+1;// is lower_bound able to do?
/*long long num_max=a[0];//zhongshu
long long nums_max=0;//the size of num1
long long nums_cur=0;
int l_max=0,r_max=0,l_cur=0,r_cur=0;// later test its name to ensure it's legal 

void get_num(){
	for(int i=1;i<n;++i){
		if(a[i]==a[i-1]){
			++nums_cur;
			++r_cur;
			if(nums_cur>nums_max){
				nums_max=nums_cur;
				num_max=a[i];
				l_max=l_cur;
				r_max=r_cur;
			}
		}
		if(a[i]!=a[i-1]){
			nums_cur=1;
			l_cur=i;
			r_cur=i;
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;++i){
		cin>>a[i];
	}
	sort(a,a+n);
/*	for(int i=1;i<n;++i){
		if(a[i]!=a[i-1]){
			cur=a[i];
			num3=1;
			continue;
		}
		if(num3>num2){
			num2=mun3;
			num3=0;
			num1=a[i];
		}
	}
	for(int i=1;i<n;++i){
		if(a[i]==a[i-1]){
			++num3;++r2;
			if(num3>num2){
				num2=num3;
				r1=r2;
				l1=l2;
			}
			continue;
		}
		if(a[i]!=a[i-1]){
			num3=0;
			l2=i;
			r2=i;
		}
	}*/
	/*get_num();
	for(int i=0;i<l_max;++i){
		b[i]=a[i];
	}
	sort(b,b+l_max);
	for(int i=0;i<l_max;++i){
		if(m>=(num_max-a[i])){
			m-=(num_max-a[i]);
			++nums_max;
		}else{
			break;
		}
	}
	cout<<nums_max<<'\n';
	return 0;
	/*d=a[1]-a[0];
		for(int i=1;i<n;++i){
		    if(a[i]-a[i-1]!=d)f=0;
	    }
	    if(f){//for 13-18
	    for(int i=0;i<n,s1[i]<=m;++i){
	        ans=i+1;
	    }	/*or(int i=1;i<n;++i){
	    		if(s[ans-1]<=m){
	    			ans++;
				}
			}
			int q=1;
			while(1ll*d*(q+2)*(q+1)<=m*2)++q;
			cout<<q<<'\n';
	    	return 0;
		}*/
//}*/
#include<bits/stdc++.h>
using namespace std;
#define MAXN 500005

long long  n,m;
long long a[MAXN],s[MAXN],b[MAXN],s1[MAXN];
int d=0;
bool f=1;
long long max1=0;
int ans=0;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;++i){
		cin>>a[i];
		b[i]=a[i]-a[0];
	}
	sort(a,a+n);
	sort(b,b+n);
	max1=a[0];
	s[0]=a[0];
	for(int i=1;i<n;++i){
		max1=max(a[i],max1);
		s[i]=s[i-1]+a[i];
		s1[i]=s1[i-1]+b[i];
	}
	if(n>=2){
		for(int i=0;i<n;++i){
		    int l=0;
			while((i-l)*a[i]-s[i-1]+s[l-1]>m)++l;
			ans=max(i-l+1,ans);
		}
		cout<<ans<<'\n';
	}else{
		cout<<1<<'\n';
	}
	return 0;
}
