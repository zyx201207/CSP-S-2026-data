#include<bits/stdc++.h>
char a[5],b[5],c[5],d[5];
bool i,j,k,l;
int main(){
	fscanf(fopen("travel.in","r"),
		"%s%s%s%s",a,b,c,d);
	i=*a==*c&&a[1]==c[1];
	j=i&&*b==*d&&b[1]==d[1];
	k=j&&(b[2]<'D')==(d[2]<'D');
	l=k&&abs(b[2]-d[2])==1;
	fprintf(fopen("travel.out","w"),
		"%d%d%d%d",i,j,k,l);
}
