#include<bits/stdc++.h>
using namespace std;
struct ac{
	long long a;
	char c;
}zheng[200150],fan[200150];
long long a[200150],sum,mid,ans;
int n;
char c[200150];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		long long as;
		cin>>as>>c[i];
		sum+=as;
		a[i]=as;
	}
	mid=sum/2;
	long long  ls=mid;
	for(int i=0;i<n;i++){
		if(ls<=0){
			break;
		}
		if(a[i]>ls){
			zheng[i].a=ls;
			zheng[i].c=c[i];
			break;
		}
		else{
			zheng[i].a=a[i];
			zheng[i].c=c[i];
			ls-=a[i];
		}
	}
	ls=mid;
	long long j=0;
	for(int i=n-1;i>=0;i--){
		if(ls<=0){
			break;
		}
		if(a[i]>ls){
			fan[j].a=ls;
			fan[j].c=c[i];
			break;
		}
		else{
			fan[j].a=a[i];
			fan[j].c=c[i];
			ls-=a[i];
		}
		j++;
	}/*
	//----------------------------
	cout<<mid<<endl;
	for(int i=0;i<n;i++){
		cout<<zheng[i].a<<' '<<zheng[i].c<<endl;
	}
	cout<<'r'<<endl;
	for(int i=0;i<n;i++){
		cout<<fan[i].a<<' '<<fan[i].c<<endl;
	}
	//------------------------------
	*/
	//-----
	//long long iu,ju,iju;
//	iu=0;ju=0;iju=0;
	//----
	long long i=0;
	j=0;
	while(1){
		//cout<<i<<j;
		if(zheng[i].a==0){
			break;
		}
		if(zheng[i].a>fan[j].a){
			if(zheng[i].c==fan[j].c){
				zheng[i].a-=fan[j].a;
			}
			else{
				ans+=fan[j].a;
				zheng[i].a-=fan[j].a;
			}
			j++;
			//ju++;
		//	cout<<"j";
		}
		else if(zheng[i].a<fan[j].a){
			if(zheng[i].c==fan[j].c){
				fan[i].a-=zheng[j].a;
			}
			else{
				ans+=zheng[j].a;
				fan[i].a-=zheng[j].a;
			}
			i++;
		//	iu++;
		//	cout<<"i";
		}
		else{
			if(zheng[i].c==fan[j].c){
				//cout<<'l';
			}
			else{
				ans+=fan[j].a;
			}
			i++;
			j++;
		//	iju++;
		//	cout<<"ij";
		}
		//cout<<ans<<endl;
	}
//	cout<<iu<<' '<<ju<<' '<<iju<<endl;
	cout<<ans;
	return 0;
} 
