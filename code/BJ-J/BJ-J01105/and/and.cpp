#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(m==1){
        int maxx=-2147483646;
        for(int i=1;i<=n;i++){
            maxx=max(maxx,a[i]);
        }
        cout<<maxx;
    }
    else if(m==2){
        int maxx=-2147483646;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                maxx=max(maxx,a[i]&a[j]);
            }
        }
        cout<<maxx;
    }
    else if(m==3){
        int maxx=-2147483646;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int z=j+1;z<=n;z++){
                    maxx=max(maxx,a[i]&a[j]&a[z]);
                }
            }
        }
        cout<<maxx;
    }else if(m==4){
        int maxx=-2147483646;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int z=j+1;z<=n;z++){
                    for(int a1=z+1;a1<=n;a1++){
                        maxx=max(maxx,a[i]&a[j]&a[z]&a[a1]);
                    }
                }
            }
        }
        cout<<maxx;
    }else if(m==5){
        int maxx=-2147483646;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int z=j+1;z<=n;z++){
                    for(int a1=z+1;a1<=n;a1++){
                        for(int b=a1+1;b<=n;b++){
                            maxx=max(maxx,a[i]&a[j]&a[z]&a[a1]&a[b]);
                        }
                    }
                }
            }
        }
        cout<<maxx;
    }else if(m==6){
        int maxx=-2147483646;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int z=j+1;z<=n;z++){
                    for(int a1=z+1;a1<=n;a1++){
                        for(int b=a1+1;b<=n;b++){
                            for(int c=b+1;c<=n;c++){
                                maxx=max(maxx,a[i]&a[j]&a[z]&a[a1]&a[b]&a[c]);
                            }
                        }
                    }
                }
            }
        }
        cout<<maxx;
    }else if(m==7){
        int maxx=-2147483646;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int z=j+1;z<=n;z++){
                    for(int a1=z+1;a1<=n;a1++){
                        for(int b=a1+1;b<=n;b++){
                            for(int c=b+1;c<=n;c++){
                                for(int d=c+1;d<=n;d++){
                                    maxx=max(maxx,a[i]&a[j]&a[z]&a[a1]&a[b]&a[c]&a[d]);
                                }
                            }
                        }
                    }
                }
            }
        }
        cout<<maxx;
    }else if(m==8){
        int maxx=-2147483646;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int z=j+1;z<=n;z++){
                    for(int a1=z+1;a1<=n;a1++){
                        for(int b=a1+1;b<=n;b++){
                            for(int c=b+1;c<=n;c++){
                                for(int d=c+1;d<=n;d++){
                                    for(int e=d+1;e<=n;e++){
                                        maxx=max(maxx,a[i]&a[j]&a[z]&a[a1]&a[b]&a[c]&a[d]&a[e]);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout<<maxx;
    }
    else if(m==9){
        int maxx=-2147483646;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int z=j+1;z<=n;z++){
                    for(int a1=z+1;a1<=n;a1++){
                        for(int b=a1+1;b<=n;b++){
                            for(int c=b+1;c<=n;c++){
                                for(int d=c+1;d<=n;d++){
                                    for(int e=d+1;e<=n;e++){
                                        for(int f=e+1;f<=n;f++){
                                            maxx=max(maxx,a[i]&a[j]&a[z]&a[a1]&a[b]&a[c]&a[d]&a[e]&a[f]);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        cout<<maxx;
    }else if(m==10){
        int maxx=-2147483646;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int z=j+1;z<=n;z++){
                    for(int a1=z+1;a1<=n;a1++){
                        for(int b=a1+1;b<=n;b++){
                            for(int c=b+1;c<=n;c++){
                                for(int d=c+1;d<=n;d++){
                                    for(int e=d+1;e<=n;e++){
                                        for(int f=e+1;f<=n;f++){
                                            for(int g=f+1;g<=n;g++){
                                                maxx=max(maxx,a[i]&a[j]&a[z]&a[a1]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        cout<<maxx;
    }else if(m==11){
        int maxx=-2147483646;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int z=j+1;z<=n;z++){
                    for(int a1=z+1;a1<=n;a1++){
                        for(int b=a1+1;b<=n;b++){
                            for(int c=b+1;c<=n;c++){
                                for(int d=c+1;d<=n;d++){
                                    for(int e=d+1;e<=n;e++){
                                        for(int f=e+1;f<=n;f++){
                                            for(int g=f+1;g<=n;g++){
                                                for(int h=g+1;h<=n;h++){
                                                    maxx=max(maxx,a[i]&a[j]&a[z]&a[a1]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        cout<<maxx;
    }
    else if(m==12){
        int maxx=-2147483646;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int z=j+1;z<=n;z++){
                    for(int a1=z+1;a1<=n;a1++){
                        for(int b=a1+1;b<=n;b++){
                            for(int c=b+1;c<=n;c++){
                                for(int d=c+1;d<=n;d++){
                                    for(int e=d+1;e<=n;e++){
                                        for(int f=e+1;f<=n;f++){
                                            for(int g=f+1;g<=n;g++){
                                                for(int h=g+1;h<=n;h++){
                                                    for(int k=h+1;k<=n;k++){
                                                        maxx=max(maxx,a[i]&a[j]&a[z]&a[a1]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[k]);
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        cout<<maxx;
    }else if(m==13){
        int maxx=-2147483646;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int z=j+1;z<=n;z++){
                    for(int a1=z+1;a1<=n;a1++){
                        for(int b=a1+1;b<=n;b++){
                            for(int c=b+1;c<=n;c++){
                                for(int d=c+1;d<=n;d++){
                                    for(int e=d+1;e<=n;e++){
                                        for(int f=e+1;f<=n;f++){
                                            for(int g=f+1;g<=n;g++){
                                                for(int h=g+1;h<=n;h++){
                                                    for(int k=h+1;k<=n;k++){
                                                        for(int l=k+1;l<=n;l++){
                                                            maxx=max(maxx,a[i]&a[j]&a[z]&a[a1]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[k]&a[l]);
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        cout<<maxx;
    }else if(m==14){
        int maxx=-2147483646;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int z=j+1;z<=n;z++){
                    for(int a1=z+1;a1<=n;a1++){
                        for(int b=a1+1;b<=n;b++){
                            for(int c=b+1;c<=n;c++){
                                for(int d=c+1;d<=n;d++){
                                    for(int e=d+1;e<=n;e++){
                                        for(int f=e+1;f<=n;f++){
                                            for(int g=f+1;g<=n;g++){
                                                for(int h=g+1;h<=n;h++){
                                                    for(int k=h+1;k<=n;k++){
                                                        for(int l=k+1;l<=n;l++){
                                                            for(int A=l+1;A<=n;A++){
                                                                maxx=max(maxx,a[i]&a[j]&a[z]&a[a1]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[k]&a[l]&a[A]);
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        cout<<maxx;
    }else if(m==15){
        int maxx=-2147483646;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int z=j+1;z<=n;z++){
                    for(int a1=z+1;a1<=n;a1++){
                        for(int b=a1+1;b<=n;b++){
                            for(int c=b+1;c<=n;c++){
                                for(int d=c+1;d<=n;d++){
                                    for(int e=d+1;e<=n;e++){
                                        for(int f=e+1;f<=n;f++){
                                            for(int g=f+1;g<=n;g++){
                                                for(int h=g+1;h<=n;h++){
                                                    for(int k=h+1;k<=n;k++){
                                                        for(int l=k+1;l<=n;l++){
                                                            for(int A=l+1;A<=n;A++){
                                                                for(int B=A+1;B<=n;B++){
                                                                    maxx=max(maxx,a[i]&a[j]&a[z]&a[a1]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[k]&a[l]&a[A]&a[B]);
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        cout<<maxx;
    }
    else if(m==16){
        int maxx=-2147483646;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int z=j+1;z<=n;z++){
                    for(int a1=z+1;a1<=n;a1++){
                        for(int b=a1+1;b<=n;b++){
                            for(int c=b+1;c<=n;c++){
                                for(int d=c+1;d<=n;d++){
                                    for(int e=d+1;e<=n;e++){
                                        for(int f=e+1;f<=n;f++){
                                            for(int g=f+1;g<=n;g++){
                                                for(int h=g+1;h<=n;h++){
                                                    for(int k=h+1;k<=n;k++){
                                                        for(int l=k+1;l<=n;l++){
                                                            for(int A=l+1;A<=n;A++){
                                                                for(int B=A+1;B<=n;B++){
                                                                    for(int C=B+1;C<=n;C++){
                                                                        maxx=max(maxx,a[i]&a[j]&a[z]&a[a1]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[k]&a[l]&a[A]&a[B]&a[C]);
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        cout<<maxx;
    }
    else if(m==17){
        int maxx=-2147483646;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int z=j+1;z<=n;z++){
                    for(int a1=z+1;a1<=n;a1++){
                        for(int b=a1+1;b<=n;b++){
                            for(int c=b+1;c<=n;c++){
                                for(int d=c+1;d<=n;d++){
                                    for(int e=d+1;e<=n;e++){
                                        for(int f=e+1;f<=n;f++){
                                            for(int g=f+1;g<=n;g++){
                                                for(int h=g+1;h<=n;h++){
                                                    for(int k=h+1;k<=n;k++){
                                                        for(int l=k+1;l<=n;l++){
                                                            for(int A=l+1;A<=n;A++){
                                                                for(int B=A+1;B<=n;B++){
                                                                    for(int C=B+1;C<=n;C++){
                                                                        for(int D=C+1;D<=n;D++){
                                                                            maxx=max(maxx,a[i]&a[j]&a[z]&a[a1]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[k]&a[l]&a[A]&a[B]&a[C]&a[D]);
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        cout<<maxx;
    }
    else if(m==18){
        int maxx=-2147483646;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int z=j+1;z<=n;z++){
                    for(int a1=z+1;a1<=n;a1++){
                        for(int b=a1+1;b<=n;b++){
                            for(int c=b+1;c<=n;c++){
                                for(int d=c+1;d<=n;d++){
                                    for(int e=d+1;e<=n;e++){
                                        for(int f=e+1;f<=n;f++){
                                            for(int g=f+1;g<=n;g++){
                                                for(int h=g+1;h<=n;h++){
                                                    for(int k=h+1;k<=n;k++){
                                                        for(int l=k+1;l<=n;l++){
                                                            for(int A=l+1;A<=n;A++){
                                                                for(int B=A+1;B<=n;B++){
                                                                    for(int C=B+1;C<=n;C++){
                                                                        for(int D=C+1;D<=n;D++){
                                                                            for(int E=D+1;E<=n;E++){
                                                                                maxx=max(maxx,a[i]&a[j]&a[z]&a[a1]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[k]&a[l]&a[A]&a[B]&a[C]&a[D]&a[E]);
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        cout<<maxx;
    } else if(m==19){
        int maxx=-2147483646;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int z=j+1;z<=n;z++){
                    for(int a1=z+1;a1<=n;a1++){
                        for(int b=a1+1;b<=n;b++){
                            for(int c=b+1;c<=n;c++){
                                for(int d=c+1;d<=n;d++){
                                    for(int e=d+1;e<=n;e++){
                                        for(int f=e+1;f<=n;f++){
                                            for(int g=f+1;g<=n;g++){
                                                for(int h=g+1;h<=n;h++){
                                                    for(int k=h+1;k<=n;k++){
                                                        for(int l=k+1;l<=n;l++){
                                                            for(int A=l+1;A<=n;A++){
                                                                for(int B=A+1;B<=n;B++){
                                                                    for(int C=B+1;C<=n;C++){
                                                                        for(int D=C+1;D<=n;D++){
                                                                            for(int E=D+1;E<=n;E++){
                                                                                for(int F=E+1;F<=n;F++){
                                                                                    maxx=max(maxx,a[i]&a[j]&a[z]&a[a1]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[k]&a[l]&a[A]&a[B]&a[C]&a[D]&a[E]&a[F]);
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        cout<<maxx;
    }else if(m==19){
        int maxx=-2147483646;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int z=j+1;z<=n;z++){
                    for(int a1=z+1;a1<=n;a1++){
                        for(int b=a1+1;b<=n;b++){
                            for(int c=b+1;c<=n;c++){
                                for(int d=c+1;d<=n;d++){
                                    for(int e=d+1;e<=n;e++){
                                        for(int f=e+1;f<=n;f++){
                                            for(int g=f+1;g<=n;g++){
                                                for(int h=g+1;h<=n;h++){
                                                    for(int k=h+1;k<=n;k++){
                                                        for(int l=k+1;l<=n;l++){
                                                            for(int A=l+1;A<=n;A++){
                                                                for(int B=A+1;B<=n;B++){
                                                                    for(int C=B+1;C<=n;C++){
                                                                        for(int D=C+1;D<=n;D++){
                                                                            for(int E=D+1;E<=n;E++){
                                                                                for(int F=E+1;F<=n;F++){
                                                                                    for(int G=F+1;G<=n;G++){
                                                                                        maxx=max(maxx,a[i]&a[j]&a[z]&a[a1]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[k]&a[l]&a[A]&a[B]&a[C]&a[D]&a[E]&a[F]&a[G]);
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        cout<<maxx;
    }
    else{
        int maxx=-2147483646;
        for(int i=1;i<=n;i++){
            maxx=max(maxx,a[i]);
        }
        cout<<maxx;
    }
    return 0;
}
