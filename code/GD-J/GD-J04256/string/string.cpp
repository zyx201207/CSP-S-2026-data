#include<iostream>
using namespace std;
struct part{
	long long n,v;
};
part a[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long len=0;
	for(int i=0;i<n;i++){
		char t;
		cin>>a[i].n>>t;
		a[i].v=t-'a';
		len+=a[i].n;
	}
	long long m=len/2;
	int lv=a[0].v,rv=a[n-1].v,ln=min(a[0].n,m),rn=min(a[n-1].n,m),li=0,ri=n-1;
	long long ans=0;
	while(m>0){
		if(lv==rv){
			if(ln<rn){
				rn-=ln;
				m-=ln;
				li++; 
				lv=a[li].v;
				ln=min(a[li].n,m);
			}
			else if(ln>rn){
				ln-=rn;
				m-=rn;
				ri--;
				rv=a[ri].v;
				rn=min(a[ri].n,m);
			}
			else{
				m-=ln;
				li++; 
				lv=a[li].v;
				ln=min(a[li].n,m);
				ri--;
				rv=a[ri].v;
				rn=min(a[ri].n,m);
			}
		}
		else{
			if(ln<rn){
				ans+=ln;
				rn-=ln;
				m-=ln;
				li++; 
				lv=a[li].v;
				ln=min(a[li].n,m);
			}
			else if(ln>rn){
				ans+=rn;
				ln-=rn;
				m-=rn;
				ri--;
				rv=a[ri].v;
				rn=min(a[ri].n,m);
			}
			else{
				ans+=ln;
				m-=ln;
				li++; 
				lv=a[li].v;
				ln=min(a[li].n,m);
				ri--;
				rv=a[ri].v;
				rn=min(a[ri].n,m);
			}	
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
