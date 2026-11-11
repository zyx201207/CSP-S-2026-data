#include <iostream>
using namespace std;
int n;
long long a[200005],ra[200100],suma,mid,isodd;
char c[200005],rc[200100];
#define min(a,b) (a<b ? a:b)
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		suma+=a[i];
	}
	if(suma&1ll){
		isodd=1,mid=suma/2+1;
		long long ans=0;
		long long nfind=0,lf=0,rd=0,to=0;
		int idx=1,firaaa=0;
		for(int i=1;i<=n;i++,idx++){
			if(nfind+a[i]>=mid && !firaaa){
//				cout<<nfind<<" lLL "<<'\n';
				lf=mid-nfind-1;
				rd=nfind+a[i]-mid;
				if(lf){
					ra[idx]=lf;
				rc[idx]=c[i];
				idx++;
				}
				ra[idx]=1;
				rc[idx]=c[i];
				to=idx;
				idx++;
				ra[idx]=rd;
				rc[idx]=c[i];
				firaaa=1;
			}
			else{
//				cout<<nfind<<" "<<'\n';
				nfind+=a[i];
				ra[idx]=a[i];
				rc[idx]=c[i];
			}
		}
		idx--;
//		cout<<idx<<"\n";
//		
//		for(int i=1;i<=idx;i++){
//			cout<<ra[i]<<" "<<rc[i]<<"\n";;
//		}
		long long l_idx=to-1,r_idx=to+1;
		while(l_idx>0 && r_idx<=idx){
			if(rc[l_idx]!=rc[r_idx]){
				ans+=min(ra[l_idx],ra[r_idx]);
//				cout<<l_idx<<" "<<r_idx<<" "<<ra[l_idx]<<" "<<ra[r_idx]<<" "<<ans<<" has diff\n "; //debug
			}
			if(ra[l_idx]<ra[r_idx]){
//				cout<<l_idx<<" "<<r_idx<<" "<<ra[l_idx]<<" "<<ra[r_idx]<<" "<<ans<<" left < right \n"; //debug
				ra[r_idx]-=ra[l_idx];
				ra[l_idx]=0;
				l_idx--;
			}
			else if(ra[l_idx]>ra[r_idx]){
//				cout<<l_idx<<" "<<r_idx<<" "<<ra[l_idx]<<" "<<ra[r_idx]<<" "<<ans<<" left > right \n"; //debug
				ra[l_idx]-=ra[r_idx];
				ra[r_idx]=0;
				r_idx++;
			}
			else{
//				cout<<l_idx<<" "<<r_idx<<" "<<ra[l_idx]<<" "<<ra[r_idx]<<" "<<ans<<" the same \n"; //debug
				ra[r_idx]=ra[l_idx]=0;
				l_idx--,r_idx++;
			}
		}
		cout<<ans;
		return 0;
	}
	else{
		isodd=0;
		mid=suma/2;
		long long ans=0;
		long long nfind=0;
		int idx=1,firaaa=0;
		int cutmid=0;
		long long l_idx,r_idx;
		for(int i=1;i<=n;i++,idx++){
			
			if(nfind+a[i]>mid &&  !firaaa){
//				cout<<nfind<<" lLL "<<'\n';
				cutmid=a[i]/2;
				ra[idx]=cutmid;
				rc[idx]=c[i];
				l_idx=idx;
				idx++;
				ra[idx]=cutmid;
				rc[idx]=c[i];
				r_idx=idx;
				firaaa=1;
			}
			else{
//				cout<<nfind<<" "<<'\n';
				nfind+=a[i];
				ra[idx]=a[i];
				rc[idx]=c[i];
			}
			if(nfind==mid){
//				cout<<nfind<<" ths"<<'\n';
				firaaa=1;
				l_idx=n/2,r_idx=n/2+1;
			}
		}
		idx--;
//		cout<<idx<<"\n";
//		
//		for(int i=1;i<=idx;i++){
//			cout<<ra[i]<<" "<<rc[i]<<"\n";;
//		}
//		cout<<l_idx<<" "<<r_idx<<"\n";
		while(l_idx>0 && r_idx<=idx){
			if(rc[l_idx]!=rc[r_idx]){
				ans+=min(ra[l_idx],ra[r_idx]);
//				cout<<l_idx<<" "<<r_idx<<" "<<ra[l_idx]<<" "<<ra[r_idx]<<" "<<ans<<" has diff\n "; //debug
			}
			if(ra[l_idx]<ra[r_idx]){
//				cout<<l_idx<<" "<<r_idx<<" "<<ra[l_idx]<<" "<<ra[r_idx]<<" "<<ans<<" left < right \n"; //debug
				ra[r_idx]-=ra[l_idx];
				ra[l_idx]=0;
				l_idx--;
			}
			else if(ra[l_idx]>ra[r_idx]){
//				cout<<l_idx<<" "<<r_idx<<" "<<ra[l_idx]<<" "<<ra[r_idx]<<" "<<ans<<" left > right \n"; //debug
				ra[l_idx]-=ra[r_idx];
				ra[r_idx]=0;
				r_idx++;
			}
			else{
//				cout<<l_idx<<" "<<r_idx<<" "<<ra[l_idx]<<" "<<ra[r_idx]<<" "<<ans<<" the same \n"; //debug
				ra[r_idx]=ra[l_idx]=0;
				l_idx--,r_idx++;
			}
		}
		cout<<ans;
		return 0;
	}
	
	return 0;
} 
