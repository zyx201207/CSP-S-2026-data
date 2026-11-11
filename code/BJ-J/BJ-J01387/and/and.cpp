#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int mx=-1;
void solve1(){
    if(m==1)cout<<mx;
    if(m==2){
        int tans=-1;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
               tans=max(tans,a[i]&a[j]);
            }
        }
        cout<<tans;
    }
    if(m==3){
        int tans=-1;
        for(int i1=1;i1<=n;i1++){
            for(int i2=i1+1;i2<=n;i2++){
                for(int i3=i2+1;i3<=n;i3++){
                    tans=max(tans,a[i1]&a[i2]&a[i3]);
                }
            }
        }
        cout<<tans;
    }
    if(m==4){
        int tans=-1;
        for(int i1=1;i1<=n;i1++){
            for(int i2=i1+1;i2<=n;i2++){
                for(int i3=i2+1;i3<=n;i3++){
                    for(int i4=i3+1;i4<=n;i4++){
                        tans=max(tans,a[i1]&a[i2]&a[i3]&a[i4]);
                    }
                }
            }
        }
        cout<<tans;
    }
    if(m==5){
        int tans=-1;
        for(int i1=1;i1<=n;i1++){
            for(int i2=i1+1;i2<=n;i2++){
                for(int i3=i2+1;i3<=n;i3++){
                    for(int i4=i3+1;i4<=n;i4++){
                        for(int i5=i4+1;i5<=n;i5++){
                            tans=max(tans,a[i1]&a[i2]&a[i3]&a[i4]&a[i5]);
                        }
                    }
                }
            }
        }
        cout<<tans;
    }
    if(m==6){
        int tans=-1;
        for(int i1=1;i1<=n;i1++){
            for(int i2=i1+1;i2<=n;i2++){
                for(int i3=i2+1;i3<=n;i3++){
                    for(int i4=i3+1;i4<=n;i4++){
                        for(int i5=i4+1;i5<=n;i5++){
                            for(int i6=i5+1;i6<=n;i6++){
                                tans=max(tans,a[i1]&a[i2]&a[i3]&a[i4]&a[i5]&a[i6]);
                            }

                        }
                    }
                }
            }
        }
        cout<<tans;
    }
    if(m==7){
        int tans=-1;
        for(int i1=1;i1<=n;i1++){
            for(int i2=i1+1;i2<=n;i2++){
                for(int i3=i2+1;i3<=n;i3++){
                    for(int i4=i3+1;i4<=n;i4++){
                        for(int i5=i4+1;i5<=n;i5++){
                            for(int i6=i5+1;i6<=n;i6++){
                                for(int i7=i6+1;i7<=n;i7++){
                                    tans=max(tans,a[i1]&a[i2]&a[i3]&a[i4]&a[i5]&a[i6]&a[i7]);
                                }

                            }

                        }
                    }
                }
            }
        }
        cout<<tans;
    }
    if(m==8){
        int tans=-1;
        for(int i1=1;i1<=n;i1++){
            for(int i2=i1+1;i2<=n;i2++){
                for(int i3=i2+1;i3<=n;i3++){
                    for(int i4=i3+1;i4<=n;i4++){
                        for(int i5=i4+1;i5<=n;i5++){
                            for(int i6=i5+1;i6<=n;i6++){
                                for(int i7=i6+1;i7<=n;i7++){
                                    for(int i8=i7+1;i8<=n;i8++){
                                        tans=max(tans,a[i1]&a[i2]&a[i3]&a[i4]&a[i5]&a[i6]&a[i7]&a[i8]);
                                    }

                                }

                            }

                        }
                    }
                }
            }
        }
        cout<<tans;
    }
    if(m==9){
        int tans=-1;
        for(int i1=1;i1<=n;i1++){
            for(int i2=i1+1;i2<=n;i2++){
                for(int i3=i2+1;i3<=n;i3++){
                    for(int i4=i3+1;i4<=n;i4++){
                        for(int i5=i4+1;i5<=n;i5++){
                            for(int i6=i5+1;i6<=n;i6++){
                                for(int i7=i6+1;i7<=n;i7++){
                                    for(int i8=i7+1;i8<=n;i8++){
                                        for(int i9=i8+1;i9<=n;i9++){
                                            tans=max(tans,a[i1]&a[i2]&a[i3]&a[i4]&a[i5]&a[i6]&a[i7]&a[i8]&a[i9]);
                                        }

                                    }

                                }

                            }

                        }
                    }
                }
            }
        }
        cout<<tans;
    }
    if(m==10){
        int tans=-1;
        for(int i1=1;i1<=n;i1++){
            for(int i2=i1+1;i2<=n;i2++){
                for(int i3=i2+1;i3<=n;i3++){
                    for(int i4=i3+1;i4<=n;i4++){
                        for(int i5=i4+1;i5<=n;i5++){
                            for(int i6=i5+1;i6<=n;i6++){
                                for(int i7=i6+1;i7<=n;i7++){
                                    for(int i8=i7+1;i8<=n;i8++){
                                        for(int i9=i8+1;i9<=n;i9++){
                                            for(int i10=i9+1;i10<=n;i10++){
                                                tans=max(tans,a[i1]&a[i2]&a[i3]&a[i4]&a[i5]&a[i6]&a[i7]&a[i8]&a[i9]&a[i10]);
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
        cout<<tans;
    }
    if(m==11){
        int tans=-1;
        for(int i1=1;i1<=n;i1++){
            for(int i2=i1+1;i2<=n;i2++){
                for(int i3=i2+1;i3<=n;i3++){
                    for(int i4=i3+1;i4<=n;i4++){
                        for(int i5=i4+1;i5<=n;i5++){
                            for(int i6=i5+1;i6<=n;i6++){
                                for(int i7=i6+1;i7<=n;i7++){
                                    for(int i8=i7+1;i8<=n;i8++){
                                        for(int i9=i8+1;i9<=n;i9++){
                                            for(int i10=i9+1;i10<=n;i10++){
                                                for(int i11=i10+1;i11<=n;i11++){
                                                    tans=max(tans,a[i1]&a[i2]&a[i3]&a[i4]&a[i5]&a[i6]&a[i7]&a[i8]&a[i9]&a[i10]&a[i11]);
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
        cout<<tans;
    }
    if(m==12){
        int tans=-1;
        for(int i1=1;i1<=n;i1++){
            for(int i2=i1+1;i2<=n;i2++){
                for(int i3=i2+1;i3<=n;i3++){
                    for(int i4=i3+1;i4<=n;i4++){
                        for(int i5=i4+1;i5<=n;i5++){
                            for(int i6=i5+1;i6<=n;i6++){
                                for(int i7=i6+1;i7<=n;i7++){
                                    for(int i8=i7+1;i8<=n;i8++){
                                        for(int i9=i8+1;i9<=n;i9++){
                                            for(int i10=i9+1;i10<=n;i10++){
                                                for(int i11=i10+1;i11<=n;i11++){
                                                    for(int i12=i11+1;i12<=n;i12++){
                                                        tans=max(tans,a[i1]&a[i2]&a[i3]&a[i4]&a[i5]&a[i6]&a[i7]&a[i8]&a[i9]&a[i10]&a[i11]&a[i12]);
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
        cout<<tans;
    }
    if(m==13){
        int tans=-1;
        for(int i1=1;i1<=n;i1++){
            for(int i2=i1+1;i2<=n;i2++){
                for(int i3=i2+1;i3<=n;i3++){
                    for(int i4=i3+1;i4<=n;i4++){
                        for(int i5=i4+1;i5<=n;i5++){
                            for(int i6=i5+1;i6<=n;i6++){
                                for(int i7=i6+1;i7<=n;i7++){
                                    for(int i8=i7+1;i8<=n;i8++){
                                        for(int i9=i8+1;i9<=n;i9++){
                                            for(int i10=i9+1;i10<=n;i10++){
                                                for(int i11=i10+1;i11<=n;i11++){
                                                    for(int i12=i11+1;i12<=n;i12++){
                                                        for(int i13=i12+1;i13<=n;i13++){
                                                            tans=max(tans,a[i1]&a[i2]&a[i3]&a[i4]&a[i5]&a[i6]&a[i7]&a[i8]&a[i9]&a[i10]&a[i11]&a[i12]&a[i13]);
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
        cout<<tans;
    }
    if(m==14){
        int tans=-1;
        for(int i1=1;i1<=n;i1++){
            for(int i2=i1+1;i2<=n;i2++){
                for(int i3=i2+1;i3<=n;i3++){
                    for(int i4=i3+1;i4<=n;i4++){
                        for(int i5=i4+1;i5<=n;i5++){
                            for(int i6=i5+1;i6<=n;i6++){
                                for(int i7=i6+1;i7<=n;i7++){
                                    for(int i8=i7+1;i8<=n;i8++){
                                        for(int i9=i8+1;i9<=n;i9++){
                                            for(int i10=i9+1;i10<=n;i10++){
                                                for(int i11=i10+1;i11<=n;i11++){
                                                    for(int i12=i11+1;i12<=n;i12++){
                                                        for(int i13=i12+1;i13<=n;i13++){
                                                            for(int i14=i13+1;i14<=n;i14++){
                                                                tans=max(tans,a[i1]&a[i2]&a[i3]&a[i4]&a[i5]&a[i6]&a[i7]&a[i8]&a[i9]&a[i10]&a[i11]&a[i12]&a[i13]&a[i14]);
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
        cout<<tans;
    }
    if(m==15){
        int tans=-1;
        for(int i1=1;i1<=n;i1++){
            for(int i2=i1+1;i2<=n;i2++){
                for(int i3=i2+1;i3<=n;i3++){
                    for(int i4=i3+1;i4<=n;i4++){
                        for(int i5=i4+1;i5<=n;i5++){
                            for(int i6=i5+1;i6<=n;i6++){
                                for(int i7=i6+1;i7<=n;i7++){
                                    for(int i8=i7+1;i8<=n;i8++){
                                        for(int i9=i8+1;i9<=n;i9++){
                                            for(int i10=i9+1;i10<=n;i10++){
                                                for(int i11=i10+1;i11<=n;i11++){
                                                    for(int i12=i11+1;i12<=n;i12++){
                                                        for(int i13=i12+1;i13<=n;i13++){
                                                            for(int i14=i13+1;i14<=n;i14++){
                                                                for(int i15=i14+1;i15<=n;i15++){
                                                                    tans=max(tans,a[i1]&a[i2]&a[i3]&a[i4]&a[i5]&a[i6]&a[i7]&a[i8]&a[i9]&a[i10]&a[i11]&a[i12]&a[i13]&a[i14]&a[i15]);
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
        cout<<tans;
    }
    if(m==16){
        int tans=-1;
        for(int i1=1;i1<=n;i1++){
            for(int i2=i1+1;i2<=n;i2++){
                for(int i3=i2+1;i3<=n;i3++){
                    for(int i4=i3+1;i4<=n;i4++){
                        for(int i5=i4+1;i5<=n;i5++){
                            for(int i6=i5+1;i6<=n;i6++){
                                for(int i7=i6+1;i7<=n;i7++){
                                    for(int i8=i7+1;i8<=n;i8++){
                                        for(int i9=i8+1;i9<=n;i9++){
                                            for(int i10=i9+1;i10<=n;i10++){
                                                for(int i11=i10+1;i11<=n;i11++){
                                                    for(int i12=i11+1;i12<=n;i12++){
                                                        for(int i13=i12+1;i13<=n;i13++){
                                                            for(int i14=i13+1;i14<=n;i14++){
                                                                for(int i15=i14+1;i15<=n;i15++){
                                                                    for(int i16=i15+1;i16<=n;i16++){
                                                                        tans=max(tans,a[i1]&a[i2]&a[i3]&a[i4]&a[i5]&a[i6]&a[i7]&a[i8]&a[i9]&a[i10]&a[i11]&a[i12]&a[i13]&a[i14]&a[i15]&a[i16]);
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
        cout<<tans;
    }
    if(m==17){
        int tans=-1;
        for(int i1=1;i1<=n;i1++){
            for(int i2=i1+1;i2<=n;i2++){
                for(int i3=i2+1;i3<=n;i3++){
                    for(int i4=i3+1;i4<=n;i4++){
                        for(int i5=i4+1;i5<=n;i5++){
                            for(int i6=i5+1;i6<=n;i6++){
                                for(int i7=i6+1;i7<=n;i7++){
                                    for(int i8=i7+1;i8<=n;i8++){
                                        for(int i9=i8+1;i9<=n;i9++){
                                            for(int i10=i9+1;i10<=n;i10++){
                                                for(int i11=i10+1;i11<=n;i11++){
                                                    for(int i12=i11+1;i12<=n;i12++){
                                                        for(int i13=i12+1;i13<=n;i13++){
                                                            for(int i14=i13+1;i14<=n;i14++){
                                                                for(int i15=i14+1;i15<=n;i15++){
                                                                    for(int i16=i15+1;i16<=n;i16++){
                                                                        for(int i17=i16+1;i17<=n;i17++){
                                                                            tans=max(tans,a[i1]&a[i2]&a[i3]&a[i4]&a[i5]&a[i6]&a[i7]&a[i8]&a[i9]&a[i10]&a[i11]&a[i12]&a[i13]&a[i14]&a[i15]&a[i16]&a[i17]);
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
        cout<<tans;
    }
    if(m==18){
        int tans=-1;
        for(int i1=1;i1<=n;i1++){
            for(int i2=i1+1;i2<=n;i2++){
                for(int i3=i2+1;i3<=n;i3++){
                    for(int i4=i3+1;i4<=n;i4++){
                        for(int i5=i4+1;i5<=n;i5++){
                            for(int i6=i5+1;i6<=n;i6++){
                                for(int i7=i6+1;i7<=n;i7++){
                                    for(int i8=i7+1;i8<=n;i8++){
                                        for(int i9=i8+1;i9<=n;i9++){
                                            for(int i10=i9+1;i10<=n;i10++){
                                                for(int i11=i10+1;i11<=n;i11++){
                                                    for(int i12=i11+1;i12<=n;i12++){
                                                        for(int i13=i12+1;i13<=n;i13++){
                                                            for(int i14=i13+1;i14<=n;i14++){
                                                                for(int i15=i14+1;i15<=n;i15++){
                                                                    for(int i16=i15+1;i16<=n;i16++){
                                                                        for(int i17=i16+1;i17<=n;i17++){
                                                                            for(int i18=i17+1;i18<=n;i18++){
                                                                                tans=max(tans,a[i1]&a[i2]&a[i3]&a[i4]&a[i5]&a[i6]&a[i7]&a[i8]&a[i9]&a[i10]&a[i11]&a[i12]&a[i13]&a[i14]&a[i15]&a[i16]&a[i17]&a[i18]);
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
        cout<<tans;
    }
    if(m==19){
        int tans=-1;
        for(int i1=1;i1<=n;i1++){
            for(int i2=i1+1;i2<=n;i2++){
                for(int i3=i2+1;i3<=n;i3++){
                    for(int i4=i3+1;i4<=n;i4++){
                        for(int i5=i4+1;i5<=n;i5++){
                            for(int i6=i5+1;i6<=n;i6++){
                                for(int i7=i6+1;i7<=n;i7++){
                                    for(int i8=i7+1;i8<=n;i8++){
                                        for(int i9=i8+1;i9<=n;i9++){
                                            for(int i10=i9+1;i10<=n;i10++){
                                                for(int i11=i10+1;i11<=n;i11++){
                                                    for(int i12=i11+1;i12<=n;i12++){
                                                        for(int i13=i12+1;i13<=n;i13++){
                                                            for(int i14=i13+1;i14<=n;i14++){
                                                                for(int i15=i14+1;i15<=n;i15++){
                                                                    for(int i16=i15+1;i16<=n;i16++){
                                                                        for(int i17=i16+1;i17<=n;i17++){
                                                                            for(int i18=i17+1;i18<=n;i18++){
                                                                                for(int i19=i18+1;i19<=n;i19++){
                                                                                    tans=max(tans,a[i1]&a[i2]&a[i3]&a[i4]&a[i5]&a[i6]&a[i7]&a[i8]&a[i9]&a[i10]&a[i11]&a[i12]&a[i13]&a[i14]&a[i15]&a[i16]&a[i17]&a[i18]&a[i19]);
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
        cout<<tans;
    }
    if(m==20){
        int tans=a[1];
        for(int i=1;i<=n;i++)tans=tans&a[i];
        cout<<tans;
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    if(n<=20){
        solve1();
        return 0;
    }
    if(m==n){
        int tans=a[1];
        for(int i=1;i<=n;i++)tans=tans&a[i];
        cout<<tans;
        return 0;
    }
    if(m==2){
        int tans=-1;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
               tans=max(tans,a[i]&a[j]);
            }
        }
        cout<<tans;
        return 0;
    }
    cout<<mx;
    return 0;
}
