#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
int main(){
	
	freopen("string.in","r",stdin); 
	freopen("string.out","w",stdout);
	//cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	long long sum=0,ans=0;
	long long n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}int jf=sum&1;
	long long bs=sum/2;
	long long ls=0,rs=0;
	long long la=0,ra=0,li=1,ri=n;
	char lc,rc;
	int i=0;
	while(ls<bs||rs<bs){
		i++;
		//cout<<i<<"<->";
		//cout<<li<<" "<<ls<<" "<<bs<<"|||"<<ri<<" "<<rs<<" "<<rs<<endl;
		
		if(la==0){
			if(ls+a[li]<=bs){
				la=a[li];
				lc=c[li];
				ls+=a[li];
			}else{
				la=bs-ls;
				lc=c[li];
				ls=bs;
			}li++;
		}
		if(ra==0){
			if(rs+a[ri]<=bs){
				ra=a[ri];
				rc=c[ri];
				rs+=a[ri];
			}else{
				ra=bs-rs;
				rc=c[ri];
				rs=bs;
			}ri--;
		}if(la>=ra){
			//cout<<"-"<<ra<<" "<<la<<" "<<rc<<" "<<lc<<" "<<!(lc==rc)<<"-";
			la-=ra;
			ans+=ra*(!(lc==rc));
			ra=0;
		}if(ra>la){
			//cout<<"a";
			ra-=la;
			ans+=la*(!(lc==rc));
			la=0;
		}//cout<<"X5";
		//cout<<"-"<<li<<" "<<ls<<" "<<bs<<"|||"<<ri<<" "<<rs<<" "<<rs<<endl;
	}
	cout<<ans;
	return 0;

}/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
