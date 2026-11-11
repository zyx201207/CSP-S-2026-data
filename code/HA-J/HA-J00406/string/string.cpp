#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin)
	freopen("string.out,"w",stdout)
    int n=0;
	char a[2001]={0},b[2001]={0},let[1000]={0};
	int fuc=0,brt=n,ans=0;
    cin>>n;
    for(int i=0;i<n;i++){
    scanf("%d\n%s",b[i],a[i]);}
            if(n==1){
    	cout<<0<<endl;}
    for(int i=0;i<b[0];i++){
    	let[i]=a[0];
	}
	for(int i=b[0];i<b[0]+b[1];i++){
    	let[i]=a[1];
	}
    for(int i=b[0]+b[1];i<b[0]+b[1]+b[2];i++){
    	let[i]=a[2];
	}
    for(int i=b[0]+b[1]+b[2];i<b[0]+b[1]+b[2]+b[3];i++){
    	let[i]=a[3];
	}
	for(int i=b[0]+b[1]+b[2]+b[3];i<b[0]+b[1]+b[2]+b[3]+b[4];i++){
    	let[i]=a[4];
	}
	for(int i=b[0]+b[1]+b[2]+b[3]+b[4];i<b[0]+b[1]+b[2]+b[3]+b[4]+b[5];i++){
    	let[i]=a[5];
	}
		for(int i=b[0]+b[1]+b[2]+b[3]+b[4]+b[5];i<b[0]+b[1]+b[2]+b[3]+b[4]+b[5]+b[6];i++){
    	let[i]=a[6];
	}
		for(int i=b[0]+b[1]+b[2]+b[3]+b[4]+b[5]+b[6];i<b[0]+b[1]+b[2]+b[3]+b[4]+b[5]+b[6]+b[7];i++){
    	let[i]=a[7];
	}
		for(int i=b[0]+b[1]+b[2]+b[3]+b[4]+b[5]+b[6]+b[7];i<b[0]+b[1]+b[2]+b[3]+b[4]+b[5]+b[6]+b[7]+b[8];i++){
    	let[i]=a[8];
	}
		for(int i=b[0]+b[1]+b[2]+b[3]+b[4]+b[5]+b[6]+b[7]+b[8];i<b[0]+b[1]+b[2]+b[3]+b[4]+b[5]+b[6]+b[7]+b[8]+b[9];i++){
    	let[i]=a[9];
	}
    for(int j=0;j<n;j++){
    	if(a[j]==a[brt]){
    		ans+=1;
    		brt--;
		}
	}
	cout<<ans<<endl;
	return 0;
}
