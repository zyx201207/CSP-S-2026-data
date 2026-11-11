#include<iostream> 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	string a,b,c,h;
	int d,f,i=0,j=0,k=0,l=0;
	char e,g;
	cin>>d>>a>>f>>b;
	c=a[0]+a[1];
	h=b[0]+b[1];
	e=a[2];
	g=b[2];
	if(d==f)
	{
		i++;
		if(c==h){
			j++;
			if((e=='D'&&g=='F')||(e=='F'&&g=='D')||(e!='D'&&g!='F'&&e!='F'&&g!='D')){
				k++;
				if(e=='D'||g=='F')l++;
				else{
					if(e=='A'&&g=='B')l++;
					else if((e=='B'&&g=='A')||(e=='B'&&g=='C'))l++;
					else if(e=='C'&&g=='B')l++;
				}
			}
		}
	}
	cout<<i<<j<<k<<l;
	return 0;
}
